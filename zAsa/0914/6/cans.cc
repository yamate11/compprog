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

  ll N, M, S; cin >> N >> M >> S;
  // @InpVec(N, A) [V8jGe9qz]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [V8jGe9qz]

  double eps = 1e-9;
  double ans = 0;
  double remS = S;
  ll n = N;
  while (true) {
    vector<double> B(n);
    ll sum = 0;
    REP(i, 1, n + 1) {
      sum += A[n - i];
      B[n - i] = (double)sum / i;
    }
    ll n0 = ranges::max_element(B) - B.begin();
    ll len = n - n0;
    ll asum = 0;
    REP(i, n0, n) asum += A[i];
    if (len * M >= remS -eps) {
      double mean = remS / len;
      ans += asum * mean;
      cout << ans << "\n";
      return 0;
    }
    remS -= len * M;
    ans += asum * M;
    n = n0;
  }


  return 0;
}

