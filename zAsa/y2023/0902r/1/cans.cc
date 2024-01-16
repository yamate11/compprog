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

  // @InpVec(4, A) [EmFd4ojP]
  auto A = vector(4, ll());
  for (int i = 0; i < 4; i++) { ll v; cin >> v; A[i] = v; }
  // @End [EmFd4ojP]
  ll s = 0;
  REP(i, 0, 4) s += A[i];
  REP(i, 0, 4) {
    if (2 * A[i] == s) {
      cout << "Yes\n";
      return 0;
    }
  }
  REP(i, 0, 4) REP(j, i + 1, 4) {
    if (2 * (A[i] + A[j]) == s) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";

  return 0;
}

