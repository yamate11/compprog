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

  ll N; cin >> N;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  vector nbr(N, vector<ll>());
  REP(i, N - 1) {
    ll u, v; cin >> u >> v; u--; v--;
    nbr[u].push_back(v);
    nbr[v].push_back(u);
  }
  vector<ll> rec;
  vector<ll> ans(N);
  auto dfs = [&](auto rF, ll nd, ll pt) -> void {
    ll idx = lower_bound(ALL(rec), A[nd]) - rec.begin();
    ll orig;
    if (SIZE(rec) <= idx) {
      orig = -1;
      rec.push_back(A[nd]);
    }else {
      orig = rec[idx];
      rec[idx] = A[nd];
    }
    ans[nd] = SIZE(rec);
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      rF(rF, cld, nd);
    }
    if (orig == -1) {
      rec.pop_back();
    }else {
      rec[idx] = orig;
    }
  };
  dfs(dfs, 0, -1);
  for (ll a : ans) {
    cout << a << "\n";
  }
  
  return 0;
}

