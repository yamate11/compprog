#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint =  modint998244353;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a <= b){a = b; return true;} return false;}
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int a,b,c,d,mlt,lim;cin>>a>>b>>c>>d>>mlt>>lim;
  ll xx, yy; cin >> xx >> yy;
  vector dp(lim+1,vector<bool>(lim+1,false));
  dp.at(0).at(0) = true;
  rep(i,lim) rep(j,lim) {
    if(!dp.at(i).at(j)) continue;
    if(i+a*100+j<=lim) dp.at(i+a*100).at(j) = true;
    if(i+b*100+j<=lim) dp.at(i+b*100).at(j) = true;
    if(i+j+c<=lim && j+c<=i/100*mlt) dp.at(i).at(j+c) = true;
    if(i+j+d<=lim && j+d<=i/100*mlt) dp.at(i).at(j+d) = true;
  }
  long double ma = 0;
  int x=a,y=0;
  rep(i,lim+1) rep(j,lim+1) {
    if(!dp.at(i).at(j)) continue;
    if(i+j==0) continue;
    if(chmax(ma,(long double)j/(long double)(i+j))) x = i+j,y = j;
  }
  cerr << x << " " << y << endl;
  if (y == 0) {
    if (yy == 0) cout << "OK\n";
    else cout << "NG\n";
    return 0;
  }
  if (xx % x == 0 and yy % y == 0 and xx / x == yy / y) cout << "OK\n";
  else cout << "NG\n";


  return 0;
}
