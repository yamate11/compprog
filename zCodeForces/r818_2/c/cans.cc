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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> bool {
    ll N; cin >> N;
    // @InpVec(N, A) [pQiuKbSh]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [pQiuKbSh]
    // @InpVec(N, B) [djuPoJlG]
    auto B = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
    // @End [djuPoJlG]
    REP(i, 0, N) if (B[i] < A[i]) return false;
    REP(i, 0, N) if (A[i] < B[i] and B[i] > B[(i + 1) % N] + 1) return false;
    return true;
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) cout << (solve() ? "YES" : "NO") << "\n";

  return 0;
}

