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
  // @InpMVec(N, (A, B, C)) [8jv8ummB]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
    ll v3; cin >> v3; C[i] = v3;
  }
  // @End [8jv8ummB]


  CHT<long double, long double, false> cht;
  REP(i, 0, M) {
    long double b = (long double)B[i];
    cht.insert(-A[i] / b, C[i] / b);
  }
  long double eps = -1e11;
  for (auto it = cht.ds.begin(); it != cht.ds.end(); it++) {
    auto it2 = std::next(it);
    if (it2 != cht.ds.end()) {
      auto [a1, b1, d1, e1] = *it;
      auto [a2, b2, d2, e2] = *it2;
      long double lo, hi;
      if (d1 - eps <= 0 and 0 <= d2 + eps) {
        lo = 0.0;
        hi = floor(d2 + eps);
      }else if (0 <= d1 + eps) {
        lo = ceil(d1 - eps);
        hi = floor(d2 + eps);
      }else {
        continue;
      }
      if (std::next(it2) == cht.ds.end()) {
        hi = 1e9;
      }
      long double lov = a2 * lo + b2;
      long double hiv = a2 * hi + b2;
      if (hiv >= 0) {
        ll a = llround(floor(lov + eps) + 1);
        ll b = llround(floor(hiv + eps) + 1);
        ll c = hi - lo + 1;
      }

    }


  }

  return 0;
}

