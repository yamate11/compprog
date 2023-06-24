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

  // @InpVec(64, A) [C1X0CePU]
  auto A = vector(64, ll());
  for (int i = 0; i < 64; i++) { ll v; cin >> v; A[i] = v; }
  // @End [C1X0CePU]
  unsigned long long ans = 0;
  REPrev(i, 63, 0) {
    ans = (unsigned long long)2 * ans + A[i];
  }
  cout << ans << endl;

  return 0;
}

