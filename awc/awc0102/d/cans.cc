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
  // @InpMVec(N, (P, C)) [cAWloNuu]
  auto P = vector(N, ll());
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; P[i] = v1;
    ll v2; cin >> v2; C[i] = v2;
  }
  // @End [cAWloNuu]
  // @InpMVec(M, ((U, dec=1), (V, dec=1))) [1OVvp2gq]
  auto U = vector(M, ll());
  auto V = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; U[i] = v1;
    ll v2; cin >> v2; v2 -= 1; V[i] = v2;
  }
  // @End [1OVvp2gq]

  auto check = [&](ll x) -> bool {
    REP(i, 0, M) if ((x >> U[i] & 1) and not (x >> V[i] & 1)) return false;
    return true;
  };
  ll ans = 0;
  REP(x, 0, 1LL << N) {
    if (check(x)) {
      ll val = 0;
      REP(i, 0, N) if (x >> i & 1) val += P[i] - C[i];
      ans = max(ans, val);
    }
  }
  cout << ans << endl;

  return 0;
}

