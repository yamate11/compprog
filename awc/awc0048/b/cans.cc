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

  ll N; cin >> N;
  // @InpVec(N, H) [s0t0yTIG]
  auto H = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; H[i] = v; }
  // @End [s0t0yTIG]
  // @InpVec(N, D) [FPaCq1Tk]
  auto D = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; D[i] = v; }
  // @End [FPaCq1Tk]
  vector<bool> fp(N);
  REP(i, 0, N) fp[i] = H[i] > 0 and D[i] > 0;

  vector<ll> tbl(N, 0LL);
  tbl[0] = fp[0] ? 1 : 0;
  tbl[1] = (fp[1] ? 1 : 0) + tbl[0];
  REP(i, 2, N) {
    tbl[i] = (fp[i] ? 1 : 0) + min(tbl[i - 1], tbl[i - 2]);
  }
  cout << tbl[N - 1] << endl;
  return 0;
}

