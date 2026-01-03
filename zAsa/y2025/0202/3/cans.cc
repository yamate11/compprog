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

  auto solve = [&]() -> bool {
    ll N; cin >> N;
    // @InpVec(N, A) [5IjljOVC]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [5IjljOVC]

    ll odd = 0;
    ll mul4 = 0;
    ll mul2 = 0;
    REP(i, 0, N) {
      if (A[i] % 4 == 0) mul4++;
      else if (A[i] % 2 == 0) mul2++;
      else odd++;
    }
    if (odd == 0) return true;
    if (mul2 > 0) odd++;
    if (odd > mul4 + 1) return false;
    return true;
  };
  cout << (solve() ? "Yes\n" : "No\n");

  return 0;
}

