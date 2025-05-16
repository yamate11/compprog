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

  auto solve = [&]() -> void {
    ll N; cin >> N;
    // @InpVec(N, A) [PtVlBx85]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [PtVlBx85]
    enum kd_t { INIT, DEC, INC };
    kd_t mode = INIT;
    ll ans = 1;
    REP(i, 1, N) {
      ll diff = A[i] - A[i - 1];
      if (mode == INIT) {
        if (diff > 0) {
          mode = INC;
        }else if (diff < 0) {
          mode = DEC;
        }
      }else if (mode == DEC) {
        if (diff > 0) {
          mode = INC;
          ans++;
        }
      }else if (mode == INC) {
        if (diff < 0) {
          mode = DEC;
        }
      }else assert(0);
    }
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

