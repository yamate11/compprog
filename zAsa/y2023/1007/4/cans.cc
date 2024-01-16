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

  ll N, K; cin >> N >> K;
  // @InpVec(K, D) [QIJbw4FI]
  auto D = vector(K, ll());
  for (int i = 0; i < K; i++) { ll v; cin >> v; D[i] = v; }
  // @End [QIJbw4FI]
  auto ok = vector(10, true);
  REP(i, 0, K) ok[D[i]] = false;

  auto good = [&](ll x) -> bool {
    while (x > 0) {
      if (not ok[x % 10]) return false;
      x /= 10;
    }
    return true;
  };

  REP(x, N, 100*N) {
    if (good(x)) {
      cout << x << endl;
      return 0;
    }
  }

  return 0;
}

