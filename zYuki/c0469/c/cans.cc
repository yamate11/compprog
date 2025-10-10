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

  auto solve = [&]() -> void {
    // @InpVec(3, A) [NMLPE1ME]
    auto A = vector(3, ll());
    for (int i = 0; i < 3; i++) { ll v; cin >> v; A[i] = v; }
    // @End [NMLPE1ME]
    // @InpVec(3, B) [hWC6Q07K]
    auto B = vector(3, ll());
    for (int i = 0; i < 3; i++) { ll v; cin >> v; B[i] = v; }
    // @End [hWC6Q07K]
    ll va = min(A[0], B[1]) + min(A[1], B[2]) + min(A[2], B[0]);
    ll vb = 0;
    ll N = A[0] + A[1] + A[2];
    ll x0 = A[0] + B[1];
    ll x1 = A[1] + B[2];
    ll x2 = A[2] + B[0];
    ll xx = max(x0, max(x1, x2));
    if (xx > N) vb = xx - N;
    cout << vb << " " << va << "\n";

  };

  ll T; cin >> T;
  REP(t, 0, T) solve();

  return 0;
}

