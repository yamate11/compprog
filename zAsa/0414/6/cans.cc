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
  // @InpVec(N, vecP, dec=1) [unan9OtK]
  auto vecP = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; vecP[i] = v; }
  // @End [unan9OtK]
  // @InpVec(N, vecI, dec=1) [AaGoP6Mp]
  auto vecI = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; vecI[i] = v; }
  // @End [AaGoP6Mp]

  return 0;
}

