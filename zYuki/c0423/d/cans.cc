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

  ll N, H; cin >> N >> H;
  // @InpVec(N, A) [WHz2PziS]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [WHz2PziS]
  // @InpVec(N, B) [52ejx5ay]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [52ejx5ay]
  vector SA(N + 1, 0LL);
  vector SB(N + 1, 0LL);
  REP(i, 0, N) {
    SA[i + 1] = SA[i] + A[i];
    SB[i + 1] = SB[i] + B[i];
  }

  ll ans = 0;
  ll q = -1;
  ll tir = 0;
  REP(p, 0, N) {
    while (q + 1 < N and tir + B[q + 1] * (q - p + 2) <= H) {
      q++;
      tir += B[q] * (q + 1 - p);
      ll sat = SA[q + 1] - SA[p];
      ans = max(ans, sat);
    }
    if (q + 1 == N) break;
    if (q < p) {
      assert(tir == 0);
      q++;
    }else {
      tir -= SB[q + 1] - SB[p];
    }
  }
  cout << ans << endl;

  return 0;
}

