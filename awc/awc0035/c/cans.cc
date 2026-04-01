#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpVec(N, T) [RkwXIEv0]
  auto T = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; T[i] = v; }
  // @End [RkwXIEv0]
  // @InpNbrList(N, M, fwd, dir=True, dec=1) [JKjJvMSF]
  auto fwd = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    fwd[u].emplace_back(v);
  }
  // @End [JKjJvMSF]
  vector<ll> load(N);
  REP(i, 0, N) for (ll p : fwd[i]) load[p]++;
  vector<ll> cands;
  vector<bool> ng(N, false);
  REP(i, 0, N) if (load[i] > T[i]) {
    cands.push_back(i);
    ng[i] = true;
  }
  while (not cands.empty()) {
    ll nd = cands.back(); cands.pop_back();
    for (ll p : fwd[nd]) if (not ng[p]) {
      load[p]++;
      if (load[p] > T[p]) {
        cands.push_back(p);
        ng[p] = true;
      }
    }
  }
  vector<ll> ans;
  REP(i, 0, N) if (ng[i]) ans.push_back(i);
  if (ssize(ans) == 0) cout << -1 << endl;
  else {
    REPOUT(i, 0, ssize(ans), ans[i] + 1, " ");
  }

  return 0;
}

