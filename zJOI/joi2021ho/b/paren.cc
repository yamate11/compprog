#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// --------------------------------------------------------
#define FOR(i,l,r) for (ll i = (l); i < (r); ++i)
#define RFOR(i,l,r) for (ll i = (r)-1; (l) <= i; --i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define RALL(c) (c).rbegin(), (c).rend()
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))
#define MIN(c) *min_element(ALL(c))
#define MAX(c) *max_element(ALL(c))
#define SUMLL(c) accumulate(ALL(c), 0LL)
#define COUNT(c,v) count(ALL(c),(v))
#define SZ(c) ((ll)(c).size())
#define BIT(b,i) (((b)>>(i)) & 1)
#define PCNT(b) __builtin_popcountll(b)
#define CIN(c) cin >> (c)
#define COUT(c) cout << (c) << '\n'
#ifdef _LOCAL
    #define debug_bar cerr << "--------------------\n";
    #define debug(x) cerr << "l." << __LINE__ << " : " << #x << " = " << (x) << '\n'
    #define debug_pair(x) cerr << "l." << __LINE__ << " : " << #x << " = (" << x.first << "," << x.second << ")\n";
    template<class T> void debug_line(const vector<T>& ans, int l, int r, int L = 0) { cerr << "l." << L << " :"; for (int i = l; i < r; i++) { cerr << ' ' << ans[i]; } cerr << '\n'; }
#else
    #define cerr if (false) cerr
    #define debug_bar
    #define debug(x)
    #define debug_pair(x)
    template<class T> void debug_line([[maybe_unused]] const vector<T>& ans, [[maybe_unused]] int l, [[maybe_unused]] int r, [[maybe_unused]] int L = 0) {}
#endif
template<class... T> void input(T&... a) { (cin >> ... >> a); }
void print() { cout << '\n'; }
template<class T> void print(const T& a) { cout << a << '\n'; }
template<class T, class... Ts> void print(const T& a, const Ts&... b) { cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
template<class T> void cout_line(const vector<T>& ans, int l, int r) { for (int i = l; i < r; i++) { if (i != l) { cout << ' '; } cout << ans[i]; } cout << '\n'; }
template<class T> bool chmin(T& a, const T b) { if (b < a) { a = b; return 1; } return 0; }
template<class T> bool chmax(T& a, const T b) { if (a < b) { a = b; return 1; } return 0; }
ll llceil(ll a, ll b) { assert(b > 0); return (a + b - 1) / b; }
ll llpow(ll x, ll n) { assert(n >= 0); if (n == 0) { return 1; }; ll res = llpow(x, n>>1); res *= res; if (n & 1) { res *= x; } return res; }
ll bitlen(ll b) { if (b <= 0) { return 0; } return (64LL - __builtin_clzll(b)); }
ll digit_len(ll n) { assert(n >= 0); if (n == 0) { return 1; } ll sum = 0; while (n > 0) { sum++; n /= 10; } return sum; }
ll digit_sum(ll n) { assert(n >= 0); ll sum = 0; while (n > 0) { sum += n % 10; n /= 10; } return sum; }
ll digit_prod(ll n) { assert(n >= 0); if (n == 0) { return 0; } ll prod = 1; while (n > 0) { prod *= n % 10; n /= 10; } return prod; }
string toupper(const string& S) { string T(S); for (int i = 0; i < (int)T.size(); i++) { T[i] = toupper(T[i]); } return T; }
string tolower(const string& S) { string T(S); for (int i = 0; i < (int)T.size(); i++) { T[i] = tolower(T[i]); } return T; }
int a2i(const char& c) { assert(islower(c)); return (c - 'a'); }
int A2i(const char& c) { assert(isupper(c)); return (c - 'A'); }
char i2a(const int& i) { assert(0 <= i && i < 26); return ('a' + i); }
char i2A(const int& i) { assert(0 <= i && i < 26); return ('A' + i); }
using P = pair<ll,ll>;
using VP = vector<P>;
using VVP = vector<VP>;
using VS = vector<string>;
using VVS = vector<VS>;
using VLL = vector<ll>;
using VVLL = vector<VLL>;
using VVVLL = vector<VVLL>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VVVB = vector<VVB>;
using VD = vector<double>;
using VVD = vector<VD>;
using VVVD = vector<VVD>;
using VLD = vector<ld>;
using VVLD = vector<VLD>;
using VVVLD = vector<VVLD>;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
constexpr ll MOD = 1000000007;
// constexpr ll MOD = 998244353;
constexpr int inf = (1 << 30) - 1;   // 1073741824 - 1
constexpr ll INF = (1LL << 62) - 1;  // 4611686018427387904 - 1
// --------------------------------------------------------
// #include <atcoder/all>
// using namespace atcoder;


// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    ll N, Q; cin >> N >> Q;
    VLL X(N); REP(i,N) cin >> X[i];

    VP Y(N-1); REP(i,N-1) Y[i] = {X[i+1] - X[i], i};
    RSORT(Y);

    VLL ans(N,0);
    ll mn = 0, mx = 0;
    ll x = 0;
    ll pos = SZ(Y) - 1;
    while (Q--) {
        ll W; cin >> W;
        if (W == 0) continue;

        x += W;
        ll mn_old = mn;
        ll mx_old = mx;
        chmax(mx, x);
        chmin(mn, x);

        while (0 <= pos) {
            auto [len, i] = Y[pos];
            if (mx - mn < len) break;
            ans[i] += mx_old;
            ans[i+1] += (-mn_old);
            (0 <= W ? ans[i] : ans[i+1]) += len - (mx_old - mn_old);
            pos--;
        }
    }

    while (0 <= pos) {
        auto [len, i] = Y[pos--];
        ans[i] += mx;
        ans[i+1] += (-mn);
    }
    ans[0] += (-mn);
    ans[N-1] += mx;

    for (const auto& a : ans) {
        print(a);
    }

    return 0;
}
