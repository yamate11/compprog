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

  auto solve = [&]() -> ll {
    ll N; cin >> N;
    // @InpMVec(N, ((L, dec=1), (R, dec=0), (U, dec=1), (V, dec=0))) [D1mcA7qX]
    auto L = vector(N, ll());
    auto R = vector(N, ll());
    auto U = vector(N, ll());
    auto V = vector(N, ll());
    for (int i = 0; i < N; i++) {
      ll v1; cin >> v1; v1 -= 1; L[i] = v1;
      ll v2; cin >> v2; v2 -= 0; R[i] = v2;
      ll v3; cin >> v3; v3 -= 1; U[i] = v3;
      ll v4; cin >> v4; v4 -= 0; V[i] = v4;
    }
    // @End [D1mcA7qX]

    auto within = [&](ll t, ll a, ll b) -> bool {
      return a <= t and t < b;
    };

    REPrev(x, N, 1) {
      auto check = [&]() -> bool {
        ll idx = 0;
        REP(p, 0, x) {
          ll q = x - 1 - p;
          for (; idx < N and (within(p, L[idx], R[idx]) or within(q, U[idx], V[idx])); idx++);
          if (idx == N) return false;
          idx++;
        }
        return true;
      };
      if (check()) return x;
    }
    return 0;

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) cout << solve() << "\n";

  return 0;
}

