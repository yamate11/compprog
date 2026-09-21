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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpVec(N, X) [wL1T4qgU]
  auto X = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; X[i] = v; }
  // @End [wL1T4qgU]
  // @InpVec(M, P) [WvQgHp49]
  auto P = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; P[i] = v; }
  // @End [WvQgHp49]
  using ev_t = tuple<ll, ll, ll>;
  ll EVAC = 1;
  ll HOUSE = 2;
  vector<ev_t> ev;
  REP(i, 0, N) ev.emplace_back(X[i], HOUSE, i);
  REP(i, 0, M) ev.emplace_back(P[i], EVAC, i);
  ranges::sort(ev);
  ll evac_idx = -1;
  vector<ll> ans(N);
  for (auto [y, kd, i] : ev) {
    if (kd == EVAC) evac_idx = i;
    else {
      ll cur = 0;
      if (evac_idx < 0) cur = abs(P[0] - X[i]);
      else if (evac_idx == M - 1) cur = abs(P[M - 1] - X[i]);
      else cur = min(abs(P[evac_idx] - X[i]), abs(P[evac_idx + 1] - X[i]));
      ans[i] = cur;
    }
  }
  REPOUT(i, 0, N, ans[i], "\n");

  return 0;
}

