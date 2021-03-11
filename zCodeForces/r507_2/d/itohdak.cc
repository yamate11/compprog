#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  auto query = [&](ll l, ll r) {
    cout << l+1 << ' ' << r << endl;
    string s; cin >> s;
    if(l == r-1 && s == "Yes") {
      exit(0);
    }
    return s == "Yes";
  };
  ll n; int k; cin >> n >> k;
  ll l = 0, r = n;
  while(1) {
    while(r-l > 100) {
      ll mid = (l+r)/2;
      (query(l, mid) ? r : l) = mid;
      l = max(0LL, l-k);
      r = min(n, r+k);
    }
    std::random_device rnd;
    std::mt19937 mt(rnd());
    std::uniform_int_distribution<ll> randn(l, r-1);
    cerr << "l=" << l << ", r=" << r << endl;
   ll v = randn(mt);
    query(v, v+1);
    l = max(0LL, l-k);
    r = min(n, r+k);
  }
  return 0;
}
