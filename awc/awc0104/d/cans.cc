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
  // @InpVec(N, T) [sS2RWbdX]
  auto T = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; T[i] = v; }
  // @End [sS2RWbdX]
  // @InpMVec(M, ((P, dec=1), B)) [goN4FuYn]
  auto P = vector(M, ll());
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; P[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
  }
  // @End [goN4FuYn]

  using ev_tp = tuple<ll, ll, ll>;
  vector<ev_tp> ev;
  ll QUERY = 1;
  ll CHGzp = 2;
  ll CHGpn = 3;
  ll CHGnz = 4;
  ll POS = 0;
  REP(i, 0, N) {
    ev.emplace_back(i, QUERY, i);
  }
  REP(i, 0, M) {
    ev.emplace_back(P[i] - B[i], CHGzp, 0);
    ev.emplace_back(P[i], CHGpn, 0);
    ev.emplace_back(P[i] + B[i], CHGnz, 0);
  }
  REP(i, -N - 10, N + 10) ev.emplace_back(i, POS, 0);
  ranges::sort(ev);
  ll cur = 0;
  ll diff = 0;
  ll ans = 0;
  for (auto [t, kd, idx] : ev) {
    if (kd == POS) {
      cur += diff;
    }else if (kd == QUERY) {
      if (cur <= T[idx]) ans = max(ans, cur);
    }else if (kd == CHGzp) diff += 1;
    else if (kd == CHGpn) diff -= 2;
    else if (kd == CHGnz) diff += 1;
  }
  cout << ans << endl;

  return 0;
}

