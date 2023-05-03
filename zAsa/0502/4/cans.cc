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

  ll N, X; cin >> N >> X;
  vector<ll> A(N + 1), B(N + 1);
  A[0] = 1;
  B[0] = 1;
  REP(i, 0, N) {
    A[i + 1] = 2 * A[i] + 3;
    B[i + 1] = 2 * B[i] + 1;
  }
  auto func = [&](auto rF, ll n, ll x) -> ll {
    if (x == 0) return 0;
    if (n == 0) {
      assert(x == 1);
      return 1;
    }else {
      if (x == 1) return 0;
      else if (x <= 1 + A[n - 1]) return rF(rF, n - 1, x - 1);
      else if (x == 2 + A[n - 1]) return B[n - 1] + 1;
      else if (x <= 2 + 2 * A[n - 1]) return B[n - 1] + 1 + rF(rF, n - 1, x - (2 + A[n - 1]));
      else return 1 + 2 * B[n - 1];
    }
  };
  cout << func(func, N, X) << endl;

  return 0;
}

