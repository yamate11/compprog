#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rrep(i,start,end) for (ll i = start;i >= (ll)(end);i--)
#define repn(i,end) for(ll i = 0; i <= (ll)(end); i++)
#define reps(i,start,end) for(ll i = start; i < (ll)(end); i++)
#define repsn(i,start,end) for(ll i = start; i <= (ll)(end); i++)
#define each(p,a) for(auto &p:a)
typedef vector<ll> vll;
typedef vector<pair<ll ,ll>> vpll;
typedef vector<vector<pair<ll ,ll>>> vvpll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;
typedef set<ll> sll;
typedef map<ll , ll> mpll;
typedef pair<ll ,ll> pll;
typedef tuple<ll , ll , ll> tpl3;
typedef tuple<ll , ll , ll , ll> tpl4;
typedef tuple<ll , ll , ll , ll , ll> tpl5;
typedef tuple<ll , ll , ll , ll , ll , ll> tpl6;
#define LL(...) ll __VA_ARGS__; input(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__; input(__VA_ARGS__)
#define Str(...) string __VA_ARGS__; input(__VA_ARGS__)
#define Ch(...) char __VA_ARGS__; input(__VA_ARGS__)
#define all(a)  (a).begin(),(a).end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define sz(x) (ll)x.size()
#define fr first
#define sc second
// << std::fixed << std::setprecision(10)
const ll INF = 1LL << 60;
const ld EPS = 1e-9;
 
ll lceil(ll a,ll b){if(a%b==0){return a/b;}if(a>=0){return (a/b)+1;}else{return -((-a)/b);}}
ll lfloor(ll a,ll b){if(a%b==0){return a/b;}if(a>=0){return (a/b);}else{return -((-a)/b)-1;}}
inline ll positive_mod(ll a,ll m){return (a % m + m)%m;}
inline ll popcnt(ull a){ return __builtin_popcountll(a);}
//0indexed
inline ll topbit(ll a){assert(a != 0);return 63 - __builtin_clzll(a);}
inline ll smlbit(ll a){assert(a != 0);return __builtin_ctzll(a);}
template<class T> bool chmin(T& a, T b){if(a > b){a = b;return true;}return false;}
template<class T> bool chmax(T& a, T b){if(a < b){a = b;return true;}return false;}
template<typename T> std::istream &operator>>(std::istream&is,std::vector<T>&v){for(T &in:v){is>>in;}return is;}
template<typename T> std::ostream &operator<<(std::ostream&os,const std::vector<T>&v){for(auto it=std::begin(v);it!=std::end(v);){os<<*it<<((++it)!=std::end(v)?" ":"");}return os;}
template<typename T1, typename T2>std::ostream &operator<< (std::ostream &os, std::pair<T1,T2> p){os << "{" << p.first << "," << p.second << "}";return os;}
template<class... T>void input(T&... a){(cin >> ... >> a);}
void print(){cout << endl;}
template<class T, class... Ts>void print(const T& a, const Ts&... b){cout << a;((cout << ' ' << b), ...);cout << endl;}
template<class T> void pspace(const T& a){ cout << a << ' ';}
void perr(){cerr << endl;}
template<class T, class... Ts>void perr(const T& a, const Ts&... b){cerr << a;((cerr << ' ' << b), ...);cerr << endl;}
void yes(bool i = true){ return print(i?"yes":"no"); }
void Yes(bool i = true){ return print(i?"Yes":"No"); }
void YES(bool i = true){ return print(i?"YES":"NO"); }
template <class T> vector<T> &operator++(vector<T> &v) {for(auto &e : v) e++;return v;}
template <class T> vector<T> operator++(vector<T> &v, signed) {auto res = v;for(auto &e : v) e++;return res;}
template <class T> vector<T> &operator--(vector<T> &v) {for(auto &e : v) e--;return v;}
template <class T> vector<T> operator--(vector<T> &v, signed) {auto res = v;for(auto &e : v) e--;return res;}
//grid探索用
vector<ll> _ta = {0,0,1,-1,1,1,-1,-1};
vector<ll> _yo = {1,-1,0,0,1,-1,1,-1};
bool isin(ll now_i,ll now_j,ll h,ll w){return (0<=now_i && now_i < h && 0 <= now_j && now_j < w);}
  
ll lpow(ll x,ll n){ll ans = 1;while(n >0){if(n & 1)ans *= x;x *= x;n >>= 1;}return ans;}
ll Modlpow(ll x,ll n,ll m){ll ans = 1;ll a = x%m;while(n >0){if(n & 1){ans *= a;ans%= m;}a *= a;a %= m;n >>= 1;}return ans;} 
const ll MOD9 = 998244353LL;
const ll MOD10 = 1000000007LL;
 
int main(){
  ios::sync_with_stdio(false);cin.tie(nullptr);
  LL(n,m,k);
  vll h(n);cin >> h;
  vll dp(n+1,-INF);
  dp[0] = k-h[0];
  vll a(n);
  rep(i,m){
    LL(p,r);
    p--;a[p]+=r;
  }
  if(dp[0] < 0){
    cout << -1 << endl;
    return 0;
  }
  dp[0] += a[0];
  rep(i,n)if(dp[i] >= 0){
    if(i+1 < n){
      ll v = dp[i]-h[i+1];
      if(v >=0)v += a[i+1];
      chmax(dp[i+1],v);
    }
    if(i+2<n){
      ll v = dp[i]-h[i+2];
      if(v >= 0)v += a[i+2];
      chmax(dp[i+2],v);
    }
  }
  if(dp[n-1] >= 0){
    cout << dp[n-1] << endl;
  }else{
    cout << -1 << endl;
  }
  
}
