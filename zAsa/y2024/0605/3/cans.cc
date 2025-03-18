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

  ll na, nb; cin >> na >> nb;
  // @InpVec(na, A) [hLcF0MUr]
  auto A = vector(na, ll());
  for (int i = 0; i < na; i++) { ll v; cin >> v; A[i] = v; }
  // @End [hLcF0MUr]
  // @InpVec(nb, B) [EVMC2VVv]
  auto B = vector(nb, ll());
  for (int i = 0; i < nb; i++) { ll v; cin >> v; B[i] = v; }
  // @End [EVMC2VVv]

  set<ll> ss;
  REP(i, 0, na) ss.insert(A[i]);
  ll common = 0;
  REP(i, 0, nb) if (ss.contains(B[i])) common++;
  cout << (double)common / (na + nb - common) << endl;

  return 0;
}

