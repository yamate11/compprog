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
  // @InpVec(N, P, dec=1) [Pu8sTtJa]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; P[i] = v; }
  // @End [Pu8sTtJa]

  auto solve = [&]() -> ll {
    if (N == 2) {
      if (P[0] == 0) return 0;
      else return 1;
    }
    if (P[1] == (P[0] + 1) % N) {
      if (P[0] == 0) return 0;
      ll a1 = N - P[0];
      ll a2 = 1 + P[N - 1] + 1 + 1;
      return min(a1, a2);
    }else {
      ll a1 = P[0] + 1 + 1;
      ll a2 = 1 + N - P[N - 1];
      return min(a1, a2);
    }
  };

  cout << solve() << endl;
  return 0;
}

