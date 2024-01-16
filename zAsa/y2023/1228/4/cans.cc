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

  ll N; cin >> N;
  // @InpVec(N, A) [wvQxmVGN]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [wvQxmVGN]

  ll s = 0; REP(i, 0, N) s += A[i];
  ll t = 0; for (ll i = 1; i < N; i += 2) t += 2 * A[i];
  vector X(N, 0LL);
  X[0] = s - t;
  REP(i, 1, N) {
    X[i] = 2 * A[i - 1] - X[i - 1];
  }
  REPOUT(i, 0, N, X[i], " ");

  return 0;
}

