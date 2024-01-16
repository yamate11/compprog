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
  // @InpVec(N, A) [UhybcdtQ]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [UhybcdtQ]

  auto comp = [&](pll p1, pll p2) -> bool {
    auto [a1, b1] = p1;
    auto [a2, b2] = p2;
    if (a1 != a2) return a1 > a2;
    return b1 < b2;
  };
  vector<pll> vec;
  REP(i, 0, N) {
    pll p(A[i], i);
    ll j = lower_bound(ALL(vec), p, comp) - vec.begin();
    if (j == SIZE(vec)) vec.push_back(p);
    else vec[j] = p;
  }
  cout << SIZE(vec) << endl;

  return 0;
}

