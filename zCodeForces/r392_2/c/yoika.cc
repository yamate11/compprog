#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e18;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n, m, k, x, y;
  cin >> n >> m >> k >> x >> y;
  ll mx = -1, mi = -1, ser = -1;
  if(n == 1 || k/m < 1){
    mx = (k + m - 1) / m;
    mi = k / m;
    ser = k / m + (y <= k%m);
  }
  else{
    vector<vector<ll>> num_q(n, vector<ll>(m, 0));
    ll loop = k / ((2*(n-1)) * m);
    rep(i,n)rep(j,m){
      if(i == 0 || i == n-1) num_q[i][j] = loop;
      else num_q[i][j] = 2 * loop;
    }
    ll rest = k % ((2*(n-1)) * m);
    ll former = min((n-1) * m, rest);
    ll latter = max(rest - (n-1) * m, 0LL);
    rep(i,former) ++num_q[i/m][i%m];
    rep(i,latter) ++num_q[(n-1)-i/m][i%m];
    mx = -1;
    mi = INF;
    rep(i,n)rep(j,m){
      chmax(mx, num_q[i][j]);
      chmin(mi, num_q[i][j]);
    }
    ser = num_q[x-1][y-1];
  }
  cout << mx << " " << mi << " " << ser << endl;
  return 0;
}
