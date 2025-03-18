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
  cout << setprecision(25);

  cout << M_PI << endl;
  cout << M_PIl << endl;

  assert(M_PI == acos(-1));
  assert(M_PI == 4 * atan(1));
  assert(M_PI == numbers::pi);
  assert(M_PIl == acos(-1.L));
  assert(M_PIl == 4 * atan(1.L));
  assert(M_PIl == numbers::pi_v<long double>);

  return 0;
}

