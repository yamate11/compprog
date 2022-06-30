#line 1 "Contests/AtCoder_abc141/abc141_e/main.cpp"
#define aclmodint
#define aclsegtree
#include <atcoder/all>
using namespace atcoder;

#line 1 "library/me/template.cpp"
// This is a dummy line
#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for(ll i = a; i < (ll)(b); i++)
#define ALL(a) (a).begin(),(a).end()
#define END(...) { print(__VA_ARGS__); return; }

#ifdef ONLINE_JUDGE
#define DBG(...) {}
#else
#define DBG(a) { cerr << #a << ": "; dbg(a); }
#endif

using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
using ll = long long;
using VL = vector<ll>;
using VVL = vector<VL>;
using VVVL = vector<VVL>;
using VD = vector<double>;
using VVD = vector<VD>;
using VVVD = vector<VVD>;
using VS = vector<string>;
using VVS = vector<VS>;
using VVVS = vector<VVS>;
using VC = vector<char>;
using VVC = vector<VC>;
using VVVC = vector<VVC>;
using P = pair<int, int>;
using VP = vector<P>;
using VVP = vector<VP>;
using VVVP = vector<VVP>;
using LP = pair<ll, ll>;
using VLP = vector<LP>;
using VVLP = vector<VLP>;
using VVVLP = vector<VVLP>;

template <typename T>
using PQ = priority_queue<T>;
template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

constexpr int INF = 1001001001;
constexpr ll LINF = 1001001001001001001ll;
constexpr int DX[] = {1, 0, -1, 0};
constexpr int DY[] = {0, 1, 0, -1};

#ifdef aclmodint

using MI7 = modint1000000007;
using V7 = vector<MI7>;
using VV7 = vector<V7>;
using VVV7 = vector<VV7>;
using MI3 = modint998244353;
using V3 = vector<MI3>;
using VV3 = vector<V3>;
using VVV3 = vector<VV3>;

ostream &operator<<(ostream &os, const modint &x) {
    os << x.val();
    return os;
}

ostream &operator<<(ostream &os, const MI3 &x) {
    os << x.val();
    return os;
}

ostream &operator<<(ostream &os, const MI7 &x) {
    os << x.val();
    return os;
}

istream &operator>>(istream &is, modint &x) {
    int y; is >> y;
    x = y;
    return is;
}

istream &operator>>(istream &is, MI3 &x) {
    int y; is >> y;
    x = y;
    return is;
}

istream &operator>>(istream &is, MI7 &x) {
    int y; is >> y;
    x = y;
    return is;
}

#endif

void print() { cout << '\n'; }
template<typename T>
void print(const T &t) { cout << t << '\n'; }
template<typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}

#ifdef ONLINE_JUDGE
template<typename... Args>
void dbg(const Args &... args) {}
#else
void dbg() { cerr << '\n'; }
template<typename T>
void dbg(const T &t) { cerr << t << '\n'; }
template<typename Head, typename... Tail>
void dbg(const Head &head, const Tail &... tail) {
    cerr << head << ' ';
    dbg(tail...);
}
#endif

template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
    os << p.first << " " << p.second;
    return os;
}

template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
    is >> p.first >> p.second;
    return is;
}

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
    for(int i = 0; i < (int) v.size(); i++) {
        os << v[i] << (i + 1 != (int) v.size() ? " " : "");
    }
    return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
    for(T &in : v) is >> in;
    return is;
}

template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template <typename T>
pair<VI, vector<T>> compress(const vector<T> &a) {
    int n = a.size();
    vector<T> x;
    REP(i, n) x.push_back(a[i]);
    sort(ALL(x)); x.erase(unique(ALL(x)), x.end());
    VI res(n);
    REP(i, n) res[i] = lower_bound(ALL(x), a[i]) - x.begin();
    return make_pair(res, x);
}

template <typename T>
pair<vector<T>, vector<T>> factorial(int n) {
    vector<T> res(n+1), rev(n+1);
    res[0] = 1;
    REP(i, n) res[i+1] = res[i] * (i+1);
    rev[n] = 1 / res[n];
    for(int i = n; i > 0; i--) {
        rev[i-1] = rev[i] * i;
    }
    return make_pair(res, rev);
}

#ifdef aclsegtree

template<typename S>
struct value_size { S value; int size; };

template<typename S>
S min_op(S l, S r) { return min(l, r); };
template<typename S>
S max_op(S l, S r) { return max(l, r); };
template<typename S>
S sum_op(S l, S r) { return l + r; };
template<typename S>
value_size<S> sum_op_size(value_size<S> l, value_size<S> r) {
    return {l.value + r.value, l.size + r.size};
};

template<typename S>
S min_e() { return  numeric_limits<S>::max(); };
template<typename S>
S max_e() { return numeric_limits<S>::min(); };
template<typename S>
S sum_e() { return 0; }
template<typename S>
value_size<S> sum_e_size() { return {0, 0}; }
template<typename S>
value_size<S> min_e_size() { return {numeric_limits<S>::max(), 0}; }
template<typename S>
value_size<S> max_e_size() { return {numeric_limits<S>::min(), 0}; }

template<typename S, typename F>
S chmin_mapping(F f, S x) { return min(x, f); }
template<typename S, typename F>
S chmax_mapping(F f, S x) { return max(x, f); }
template<typename S, typename F>
S add_mapping(F f, S x) { return x + f; }
template<typename S, typename F>
value_size<S> add_mapping_size(F f, value_size<S> x) {
    return {x.value + x.size * f, x.size};
}
template <typename S,typename F, F ID>
S change_mapping(F f, S x) { return (f == ID? x : f); }
template <typename S,typename F, F ID>
value_size<S> change_mapping_size(F f, value_size<S> x) { 
    value_size<S> ret = {f * x.size, x.size};
    return (f == ID? x : ret); 
}
template <typename S, typename F1, typename F2>
S linear_mapping(pair<F1, F2> f, S x) { return x * f.first + f.second; }
template <typename S, typename F1, typename F2>
value_size<S> linear_mapping_size(pair<F1, F2> f, value_size<S> x) { return {x.value * f.first + x.size * f.second, x.size}; }

template<typename F>
F chmin_composition(F f, F g) { return min(f, g); }
template<typename F>
F chmax_composition(F f, F g) { return max(f, g); }
template<typename F>
F add_composition(F f, F g) { return f + g; }
template <typename F, F ID>
F change_composition(F f, F g) { return (f == ID? g : f); }
template<typename F1, typename F2>
pair<F1, F2> linear_composition(pair<F1, F2> f, pair<F1, F2> g) { return {f.first * g.first, f.first * g.second + f.second}; }

template<typename F>
F chmin_id() { return numeric_limits<F>::max(); }
template<typename F>
F chmax_id() { return numeric_limits<F>::min(); }
template<typename F>
F add_id() { return 0; }
template<typename F, F ID>
F change_id() { return ID; }
template<typename F1, typename F2>
pair<F1, F2> linear_id() { return {1, 0}; }

template<typename S>
using RSumQ = segtree<S, sum_op<S>, sum_e<S>>;
template<typename S>
using RMaxQ = segtree<S, max_op<S>, max_e<S>>;
template<typename S>
using RMinQ = segtree<S, min_op<S>, min_e<S>>;

template<typename S, typename F>
using RAddSumQ = lazy_segtree<value_size<S>, sum_op_size<S>, sum_e_size<S>,
    F, add_mapping_size<S, F>, add_composition<F>, add_id<F>>;
template<typename S, typename F>
using RAddMinQ = lazy_segtree<S, min_op<S>, min_e<S>,
    F, add_mapping<S, F>, add_composition<F>, add_id<F>>;
template<typename S, typename F>
using RAddMaxQ = lazy_segtree<S, max_op<S>, max_e<S>,
    F, add_mapping<S, F>, add_composition<F>, add_id<F>>;
template<typename S, typename F>
using RMinMinQ = lazy_segtree<S, min_op<S>, min_e<S>,
    F, chmin_mapping<S, F>, chmin_composition<F>, chmin_id<F>>;
template<typename S, typename F>
using RMaxMaxQ = lazy_segtree<S, max_op<S>, max_e<S>,
    F, chmax_mapping<S, F>, chmax_composition<F>, chmax_id<F>>;
template<typename S, typename F, F ID>
using RChangeMinQ = lazy_segtree<S, min_op<S>, min_e<S>,
    F, change_mapping<S, F, ID>,
    change_composition<F, ID>,
    change_id<F, ID>>;
template<typename S, typename F, F ID>
using RChangeMaxQ = lazy_segtree<S, max_op<S>, max_e<S>,
    F, change_mapping<S, F, ID>,
    change_composition<F, ID>,
    change_id<F, ID>>;
template<typename S, typename F, F ID>
using RChangeSumQ = lazy_segtree<value_size<S>, sum_op_size<S>, sum_e_size<S>,
    F, change_mapping_size<S, F, ID>,
    change_composition<F, ID>,
    change_id<F, ID>>;
template<typename S, typename F1, typename F2>
using RLinearMinQ = lazy_segtree<S, min_op<S>, min_e<S>,
    pair<F1, F2>, linear_mapping<S, F1, F2>,
    linear_composition<F1, F2>,
    linear_id<F1, F2>>;
template<typename S, typename F1, typename F2>
using RLinearMaxQ = lazy_segtree<S, max_op<S>, max_e<S>,
    pair<F1, F2>, linear_mapping<S, F1, F2>,
    linear_composition<F1, F2>,
    linear_id<F1, F2>>;
template<typename S, typename F1, typename F2>
using RLinearSumQ = lazy_segtree<value_size<S>, sum_op_size<S>, sum_e_size<S>,
    pair<F1, F2>, linear_mapping_size<S, F1, F2>,
    linear_composition<F1, F2>,
    linear_id<F1, F2>>;
#endif
#line 7 "Contests/AtCoder_abc141/abc141_e/main.cpp"

void solve(){
    int n; string s; cin >> n >> s;
    int ans = 0;
    REP(k, n) {
        int i = 0, j = k;
        int cnt = 0;
        while(j < n) {
            if(s[i] == s[j]) {
                cnt++;
                chmax(ans, min(k, cnt));
            }
            else cnt = 0;
            i++;
            j++;
        }
        chmax(ans, min(k, cnt));
    }
    print(ans);
}

// generated by oj-template v4.7.2 (https://github.com/online-judge-tools/template-generator)
int main() {
    // Fasterize input/output script
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(100);
    // scanf/printf user should delete this fasterize input/output script

    int t = 1;
    //cin >> t; // comment out if solving multi testcase
    for(int testCase = 1;testCase <= t;++testCase){
        solve();
    }
    return 0;
}
