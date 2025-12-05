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
    ll N, H; cin >> N >> H;
    // @InpMVec(N, (T, L, U)) [EmniIc2n]
    auto T = vector(N, ll());
    auto L = vector(N, ll());
    auto U = vector(N, ll());
    for (int i = 0; i < N; i++) {
      ll v1; cin >> v1; T[i] = v1;
      ll v2; cin >> v2; L[i] = v2;
      ll v3; cin >> v3; U[i] = v3;
    }
    // @End [EmniIc2n]

    ll lo = H, hi = H;
    REP(i, 0, N) {
      ll dt = i == 0 ? T[i] : T[i] - T[i - 1];
      hi = min(U[i], hi + dt);
      lo = max(L[i], lo - dt);
      if (lo > hi) return false;
    }
    return true;
  };


  ll T; cin >> T;
  REP(t, 0, T) cout << (solve() ? "Yes\n" : "No\n");

  return 0;
}

