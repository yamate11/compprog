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

  // @InpVec(7, A) [YL4RUi45]
  auto A = vector(7, ll());
  for (int i = 0; i < 7; i++) { ll v; cin >> v; A[i] = v; }
  // @End [YL4RUi45]
  // @InpVec(7, B) [0ciSqg7A]
  auto B = vector(7, ll());
  for (int i = 0; i < 7; i++) { ll v; cin >> v; B[i] = v; }
  // @End [0ciSqg7A]

  ll ans = 0;
  REP(i, 0, 7) ans += A[i] * B[i];
  cout << ans << endl;

  return 0;
}

