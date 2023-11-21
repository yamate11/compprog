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

  auto solve = [&]() -> ll {
    ll N, M; cin >> N >> M;
    // @InpVec(N - 1, A) [BrSr0uax]
    auto A = vector(N - 1, ll());
    for (int i = 0; i < N - 1; i++) { ll v; cin >> v; A[i] = v; }
    // @End [BrSr0uax]
    // @InpVec(N, B) [l6Nty2qj]
    auto B = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
    // @End [l6Nty2qj]

    vector<pll> ev;
    REP(i, 0, N - 1) ev.emplace_back(A[i], 1);
    REP(i, 0, N) ev.emplace_back(B[i], -1);
    sort(ALL(ev));
    ll ss = 0;
    ll vmin = 0;
    ll tmin = 0;
    ll cnt = 0;
    ll cur = 0;
    for (auto [t, sgn] : ev) {
      cur += sgn;
      if (sgn > 0) {
        ss++;
      }else if (ss > 0) {
        ss--;
        cnt++;
      }
      if (cur < vmin) {
        assert(sgn < 0);
        vmin = cur;
        tmin = t;
      }
    }
    assert(vmin < 0);
    ll w1 = min(M, tmin - 1) * (N - (cnt + 1));
    ll w2 = max(0LL, M - tmin + 1) * (N - cnt);
    return w1 + w2;
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) cout << solve() << "\n";

  return 0;
}

