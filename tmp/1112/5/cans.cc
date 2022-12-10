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

  ll N; cin >> N;
  // @InpVec(N, C) [uUwW0oqR]
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
  // @End [uUwW0oqR]
  ll vmax = 0;
  ll cur = 1;
  REP(i, 1, 2*N) {
    if (C[i % N] == C[(i + 1) % N]) {
      cur++;
      vmax = max(vmax, cur);
    }else {
      cur = 1;
    }
  }
  if (vmax > N) {
    cout << -1 << endl;
    return 0;
  }
  cout << (vmax + 1) / 2 << "\n";

  return 0;
}

