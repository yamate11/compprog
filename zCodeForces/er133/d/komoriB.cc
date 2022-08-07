#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <random>
#include <unordered_set>
//#include <atcoder/all>
//#include <boost/rational.hpp>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <boost/multiprecision/cpp_bin_float.hpp>
#ifdef _MSC_VER
#include <conio.h>
#include <ppl.h>
#include <filesystem>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <intrin.h>
int __builtin_clz(unsigned int n)
{
    unsigned long index;
    _BitScanReverse(&index, n);
    return 31 - index;
}
int __builtin_ctz(unsigned int n)
{
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
}
namespace std {
    inline int __lg(int __n) { return sizeof(int) * 8 - 1 - __builtin_clz(__n); }
}
#else
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

/** compro_io **/

/* tuple */
// out
namespace aux {
    template<typename T, unsigned N, unsigned L>
    struct tp {
        static void output(std::ostream& os, const T& v) {
            os << std::get<N>(v) << ", ";
            tp<T, N + 1, L>::output(os, v);
        }
    };
    template<typename T, unsigned N>
    struct tp<T, N, N> {
        static void output(std::ostream& os, const T& v) { os << std::get<N>(v); }
    };
}
template<typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::tuple<Ts...>& t) {
    os << '[';
    aux::tp<std::tuple<Ts...>, 0, sizeof...(Ts) - 1>::output(os, t);
    return os << ']';
}

template<class Ch, class Tr, class Container>
std::basic_ostream<Ch, Tr>& operator<<(std::basic_ostream<Ch, Tr>& os, const Container& x);

/* pair */
// out
template<class S, class T>
std::ostream& operator<<(std::ostream& os, const std::pair<S, T>& p) {
    return os << "[" << p.first << ", " << p.second << "]";
}
// in
template<class S, class T>
std::istream& operator>>(std::istream& is, std::pair<S, T>& p) {
    return is >> p.first >> p.second;
}

/* container */
// out
template<class Ch, class Tr, class Container>
std::basic_ostream<Ch, Tr>& operator<<(std::basic_ostream<Ch, Tr>& os, const Container& x) {
    bool f = true;
    os << "[";
    for (auto& y : x) {
        os << (f ? "" : ", ") << y;
        f = false;
    }
    return os << "]";
}
// in
template <
    class T,
    class = decltype(std::begin(std::declval<T&>())),
    class = typename std::enable_if<!std::is_same<T, std::string>::value>::type
>
std::istream& operator>>(std::istream& is, T& a) {
    for (auto& x : a) is >> x;
    return is;
}

std::ostream& operator<<(std::ostream& os, const std::vector<bool>& v) {
    std::string s(v.size(), ' ');
    for (int i = 0; i < v.size(); i++) s[i] = v[i] + '0';
    os << s;
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<bool>>& m) {
    for (const auto& v : m) os << v << '\n';
    return os;
}

/* struct */
template<typename T>
auto operator<<(std::ostream& out, const T& t) -> decltype(out << t.stringify()) {
    out << t.stringify();
    return out;
}

/* setup */
struct IOSetup {
    IOSetup(bool f) {
        if (f) { std::cin.tie(nullptr); std::ios::sync_with_stdio(false); }
        std::cout << std::fixed << std::setprecision(15);
    }
} iosetup(true);

/** string formatter **/
template<typename... Ts>
std::string format(const std::string& f, Ts... t) {
    size_t l = std::snprintf(nullptr, 0, f.c_str(), t...);
    std::vector<char> b(l + 1);
    std::snprintf(&b[0], l + 1, f.c_str(), t...);
    return std::string(&b[0], &b[0] + l);
}

template<typename T>
std::string stringify(const T& x) {
    std::ostringstream oss;
    oss << x;
    return oss.str();
}

/* dump */
#define DUMPOUT std::cerr
std::ostringstream DUMPBUF;
#define dump(...) do{DUMPBUF<<"  ";DUMPBUF<<#__VA_ARGS__<<" :[DUMP - "<<__LINE__<<":"<<__FUNCTION__<<"]"<<std::endl;DUMPBUF<<"    ";dump_func(__VA_ARGS__);DUMPOUT<<DUMPBUF.str();DUMPBUF.str("");DUMPBUF.clear();}while(0);
void dump_func() { DUMPBUF << std::endl; }
template <class Head, class... Tail> void dump_func(Head&& head, Tail&&... tail) { DUMPBUF << head; if (sizeof...(Tail) == 0) { DUMPBUF << " "; } else { DUMPBUF << ", "; } dump_func(std::move(tail)...); }

///* timer */
//class Timer {
//    double t = 0, paused = 0, tmp;
//public:
//    Timer() { reset(); }
//    static double time() {
//#ifdef _MSC_VER
//        return __rdtsc() / 3.0e9;
//#else
//        unsigned long long a, d;
//        __asm__ volatile("rdtsc"
//            : "=a"(a), "=d"(d));
//        return (d << 32 | a) / 3.0e9;
//#endif
//    }
//    void reset() { t = time(); }
//    void pause() { tmp = time(); }
//    void restart() { paused += time() - tmp; }
//    double elapsed_ms() const { return (time() - t - paused) * 1000.0; }
//} timer;

/* rand */
struct Xorshift {
    uint64_t x = 88172645463325252LL;
    void set_seed(unsigned seed, int rep = 100) { x = uint64_t((seed + 1) * 10007); for (int i = 0; i < rep; i++) next_int(); }
    unsigned next_int() { x = x ^ (x << 7); return x = x ^ (x >> 9); }
    unsigned next_int(unsigned mod) { x = x ^ (x << 7); x = x ^ (x >> 9); return x % mod; }
    unsigned next_int(unsigned l, unsigned r) { x = x ^ (x << 7); x = x ^ (x >> 9); return x % (r - l + 1) + l; } // inclusive
    double next_double() { return double(next_int()) / UINT_MAX; }
} rnd;

/* shuffle */
template<typename T>
void shuffle_vector(std::vector<T>& v, Xorshift& rnd) {
    int n = v.size();
    for (int i = n - 1; i >= 1; i--) {
        int r = rnd.next_int(i);
        std::swap(v[i], v[r]);
    }
}

/* split */
std::vector<std::string> split(std::string str, const std::string& delim) {
    for (char& c : str) if (delim.find(c) != std::string::npos) c = ' ';
    std::istringstream iss(str);
    std::vector<std::string> parsed;
    std::string buf;
    while (iss >> buf) parsed.push_back(buf);
    return parsed;
}

template<typename A, size_t N, typename T> inline void Fill(A(&array)[N], const T& val) {
    std::fill((T*)array, (T*)(array + N), val);
}

template<typename T, typename ...Args> auto make_vector(T x, int arg, Args ...args) { if constexpr (sizeof...(args) == 0)return std::vector<T>(arg, x); else return std::vector(arg, make_vector<T>(x, args...)); }
template<typename T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }
template<typename T> bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } return false; }

using ll = long long;
using ull = unsigned long long;
using ld = double;
//using ld = boost::multiprecision::cpp_bin_float_quad;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using namespace std;



template<typename T>
void print_vector(const std::vector<T>& v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << (i ? " " : "") << v[i];
    }
    std::cout << '\n';
}



template<typename T, T MOD>
struct modint {
    inline static constexpr T mod = MOD;
    T x;
    modint() : x(0) {}
    modint(signed t) { x = t % MOD; if (x < 0) x += MOD; }
    modint(long long t) { x = t % MOD; if (x < 0) x += MOD; }

    modint pow(long long k) {
        modint res(1), tmp(x);
        while (k) {
            if (k & 1) res *= tmp;
            tmp *= tmp;
            k >>= 1;
        }
        return res;
    }

    static modint add_identity() { return modint(0); }
    static modint mul_identity() { return modint(1); }

    modint inv() { return pow(MOD - 2); }

    modint& operator+=(modint a) { x += a.x; if (x >= MOD) x -= MOD; return *this; }
    modint& operator-=(modint a) { if (x < a.x) x += MOD; x -= a.x; return *this; }
    modint& operator*=(modint a) { x = 1LL * x * a.x % MOD; return *this; }
    modint& operator/=(modint a) { return (*this) *= a.inv(); }

    modint operator+(modint a) const { return modint(x) += a; }
    modint operator-(modint a) const { return modint(x) -= a; }
    modint operator*(modint a) const { return modint(x) *= a; }
    modint operator/(modint a) const { return modint(x) /= a; }

    modint operator+() const { return *this; }
    modint operator-() const { return x ? modint(MOD - x) : modint(x); }

    bool operator==(const modint a)const { return x == a.x; }
    bool operator!=(const modint a)const { return x != a.x; }

    static modint comb(long long n, int k) {
        modint num(1), dom(1);
        for (int i = 0; i < k; i++) {
            num *= modint(n - i);
            dom *= modint(i + 1);
        }
        return num / dom;
    }
};
template<typename T, T MOD>
istream& operator>>(istream& in, modint<T, MOD>& m) {
    long long x; in >> x;
    m.x = x % MOD; if (m.x < 0) m.x += MOD;
    return in;
}
template<typename T, T MOD>
ostream& operator<<(ostream& out, const modint<T, MOD>& m) {
    out << m.x;
    return out;
}

using mint = modint<int, 998244353>;



void solve() {
    // 2行m列

    int N, K;
    cin >> N >> K;
    int s = K; // start index
    auto ans = make_vector(mint(0), N + 1);
    auto dp0 = make_vector(mint(0), N + 1);
    auto dp1 = make_vector(mint(0), N + 1);
    dp0[0] = 1;
    while (s <= N) {
        memset(dp1.data(), 0, sizeof(mint) * (N + 1));
        for (int i = s; i <= N; i++) {
            dp1[i] = dp1[i - K] + dp0[i - K];
            ans[i] += dp1[i];
        }
        memcpy(dp0.data(), dp1.data(), sizeof(mint) * (N + 1));
        //dp0 = dp1;
        K++;
        s += K;
    }

    cout << ans[1];
    for (int i = 2; i <= N; i++) cout << ' ' << ans[i];
    cout << '\n';

}

int main() {

    int T = 1;
    //cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }

    return 0;
}
