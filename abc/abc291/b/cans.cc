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
  // @InpVec(5*N, X) [chfE1RPV]
  auto X = vector(5*N, ll());
  for (int i = 0; i < 5*N; i++) { ll v; cin >> v; X[i] = v; }
  // @End [chfE1RPV]
  sort(ALL(X));
  double s = 0;
  for (ll i = N; i < 4*N; i++) s += X[i];
  cout << s / (3 * N) << endl;

  return 0;
}

