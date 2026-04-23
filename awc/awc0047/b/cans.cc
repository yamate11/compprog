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

  ll N, M; cin >> N >> M;
  // @InpVec(N - 1, W) [0lZK0yVc]
  auto W = vector(N - 1, ll());
  for (int i = 0; i < N - 1; i++) { ll v; cin >> v; W[i] = v; }
  // @End [0lZK0yVc]
  REP(i, 0, N - 1) {
    if (W[i] == 1) {
      if (M == 0) {
        cout << i + 1 << "\n";
        return 0;
      }
      M--;
    }
  }
  cout << N << "\n";

  return 0;
}

