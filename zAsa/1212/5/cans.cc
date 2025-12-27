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
  // @InpVec(N, P) [GeNRQTtF]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; P[i] = v; }
  // @End [GeNRQTtF]
  // @InpVec(M, L) [GtvmKKSO]
  auto L = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; L[i] = v; }
  // @End [GtvmKKSO]
  // @InpVec(M, D) [8kNz5pY2]
  auto D = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; D[i] = v; }
  // @End [8kNz5pY2]

  using ev_t = pair<ll, ll>;
  vector<ev_t> ev;
  ll big = 1e18;
  REP(i, 0, N) {
    ev.emplace_back(P[i], big);
  }
  REP(i, 0, M) {
    ev.emplace_back(L[i], D[i]);
  }
  ranges::sort(ev);
  priority_queue<ll> pque;
  ll ans = accumulate(ALL(P), 0LL);
  for (auto [x, y] : ev) {
    if (y == big) {
      if (not pque.empty()) {
        ll d = pque.top(); pque.pop();
        ans -= d;
      }
    }else {
      pque.push(y);
    }
  }
  cout << ans << endl;
  return 0;
}

