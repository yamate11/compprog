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

  ll NA, NB; cin >> NA >> NB;
  // @InpVec(NA, A) [glpSmaBK]
  auto A = vector(NA, ll());
  for (int i = 0; i < NA; i++) { ll v; cin >> v; A[i] = v; }
  // @End [glpSmaBK]
  // @InpVec(NB, B) [kqcCn6Dh]
  auto B = vector(NB, ll());
  for (int i = 0; i < NB; i++) { ll v; cin >> v; B[i] = v; }
  // @End [kqcCn6Dh]

  map<ll, pll> mp;
  REP(i, 0, NA) {
    auto [x, y] = mp[A[i]];
    mp[A[i]] = pll(x + 1, y);
  }
  REP(i, 0, NB) {
    auto [x, y] = mp[B[i]];
    mp[B[i]] = pll(x, y + 1);
  }
  double p = 0.0;
  double q = 0.0;
  for (auto [n, pair] : mp) {
    auto [x, y] = pair;
    if (x > 0 and y > 0) p += 1.0;
    q += 1.0;
  }
  cout << p / q << endl;
    

  return 0;
}

