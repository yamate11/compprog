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
  ll sz = 1LL << N;
  // @InpVec(sz, A) [JCeRmkVC]
  auto A = vector(sz, ll());
  for (int i = 0; i < sz; i++) { ll v; cin >> v; A[i] = v; }
  // @End [JCeRmkVC]

  auto it1 = max_element(A.begin(), A.begin() + sz / 2);
  auto it2 = max_element(A.begin() + sz / 2, A.begin() + sz);
  ll ans;
  if (*it1 < *it2) ans = it1 - A.begin();
  else ans = it2 - A.begin();
  cout << ans + 1 << endl;

  return 0;
}

