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
  // @InpVec(N, A) [DtCkpaKj]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [DtCkpaKj]

  auto f = [&](double x) -> double {
    double ans = 0;
    REP(i, 0, N) ans += (double)(x + A[i] - min(2 * x, (double)A[i])) / N;
    return ans;
  };

  double lo = 0;
  double hi = *ranges::max_element(A);
  REP(i, 0, 200) {
    double x1 = lo + (hi - lo) / 3.0;
    double x2 = hi - (hi - lo) / 3.0;
    double v1 = f(x1);
    double v2 = f(x2);
    if (v1 > v2) lo = x1;
    else hi = x2;
  }
  cout << f(lo) << endl;

  return 0;
}

