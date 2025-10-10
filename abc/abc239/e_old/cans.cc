#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  vector<ll> X(N); REP(i, N) cin >> X[i];
  vector<vector<ll>> nbr(N);
  REP(i, N-1) {
    ll a, b; cin >> a >> b; a--; b--;
    nbr[a].push_back(b);
    nbr[b].push_back(a);
  }
  ll lim = 20;
  vector<vector<ll>> rec(N);
  auto dfs = [&](auto rF, ll nd, ll pt) -> void {
    rec[nd].push_back(X[nd]);
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      rF(rF, cld, nd);
      vector<ll> tmp;
      ll p = 0;
      ll q = 0;
      while (SIZE(tmp) < lim) {
        if (p == SIZE(rec[nd])) {
          if (q == SIZE(rec[cld])) break;
          tmp.push_back(rec[cld][q]);
          q++;
        }else if (q == SIZE(rec[cld])) {
          tmp.push_back(rec[nd][p]);
          p++;
        }else if (rec[nd][p] > rec[cld][q]) {
          tmp.push_back(rec[nd][p]);
          p++;
        }else {
          tmp.push_back(rec[cld][q]);
          q++;
        }
      }
      rec[nd] = move(tmp);
    }
  };
  dfs(dfs, 0, -1);


  REP(q, Q) {
    ll v, k; cin >> v >> k; v--; k--;
    cout << rec[v][k] << "\n";
  }

  return 0;
}

