#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<ll> parent(N);
  vector children(N, vector<ll>());
  REP(i, 1, N) {
    ll p; cin >> p; p--;
    parent[i] = p;
    children[p].push_back(i);
  }

  // @InpMVec(M, ((X, dec=1), Y)) [F18zFdQM]
  auto X = vector(M, ll());
  auto Y = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; X[i] = v1;
    ll v2; cin >> v2; Y[i] = v2;
  }
  // @End [F18zFdQM]
  vector A(N, vector<ll>());
  REP(i, 0, M) A[X[i]].push_back(i);

  vector eff(M, false);

  set<pll> ss;
  ll ans = 0;
  auto dfs = [&](auto rF, ll nd, ll pt, ll dp) -> void {
    for (ll j : A[nd]) {
      ss.emplace(dp + Y[j], j);
    }
    if (not ss.empty()) {
      auto it = prev(ss.end());
      auto [g, _j] = *it;
      if (dp <= g) ans++;
    }
    for (ll cld : children[nd]) rF(rF, cld, nd, dp + 1);
    for (ll j : A[nd]) {
      ss.erase(pll(dp + Y[j], j));
    }
  };
  dfs(dfs, 0, -1, 0);
  cout << ans << endl;

  return 0;
}

