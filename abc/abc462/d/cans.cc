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

  ll N, D; cin >> N >> D;
  // @InpMVec(N, (S, T)) [ZxcvUd13]
  auto S = vector(N, ll());
  auto T = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; S[i] = v1;
    ll v2; cin >> v2; T[i] = v2;
  }
  // @End [ZxcvUd13]
  ll IN = 1;
  ll OUT = 2;
  using ev_tp = pair<ll, ll>;
  vector<ev_tp> ev;
  REP(i, 0, N) {
    if (T[i] - S[i] >= D) {
      ev.emplace_back(S[i], IN);
      ev.emplace_back(T[i] - D + 1, OUT);
    }
  }
  ranges::sort(ev);
  ll idx = 0;
  ll cur = 0;
  ll ans = 0;
  REP(i, 0, (ll)(1e6 + 1)) {
    while (true) {
      if (idx >= ssize(ev)) break;
      auto [t, kd] = ev[idx];
      if (i < t) break;
      if (kd == IN) cur++;
      else cur--;
      idx++;
    }
    ans += cur * (cur - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}

