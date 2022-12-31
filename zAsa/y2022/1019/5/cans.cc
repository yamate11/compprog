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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, L; cin >> N >> L;
  // @InpVec(N, A) [vqVcMGmM]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [vqVcMGmM]
  ll i0 = -1;
  REP(i, 0, N - 1) if (A[i] + A[i + 1] >= L) { i0 = i; break; }
  if (i0 < 0) {
    cout << "Impossible" << endl;
    return 0;
  }
  cout << "Possible\n";
  REP(i, 0, i0) cout << i + 1 << "\n";
  REPrev(i, N - 2, i0) cout << i + 1 << "\n";

  return 0;
}

