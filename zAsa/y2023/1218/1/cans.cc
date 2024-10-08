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

  ll M; cin >> M;
  // @InpVec(M, D) [kpkgdD2A]
  auto D = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; D[i] = v; }
  // @End [kpkgdD2A]

  ll s = 0;
  REP(i, 0, M) s += D[i];
  ll k = s / 2;
  ll t = 0;
  REP(i, 0, M) {
    if (t + D[i] > k) {
      cout << i + 1 << " " << k - t + 1 << endl;
      return 0;
    }
    t += D[i];
  }

  return 0;
}

