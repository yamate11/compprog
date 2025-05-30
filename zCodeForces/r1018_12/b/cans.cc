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
    ll N, K; cin >> N >> K;
    // @InpVec(N, L) [5fYWhoQN]
    auto L = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; L[i] = v; }
    // @End [5fYWhoQN]
    // @InpVec(N, R) [3CkP9l8C]
    auto R = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; R[i] = v; }
    // @End [3CkP9l8C]

    REP(i, 0, N) if (L[i] < R[i]) swap(L[i], R[i]);
    ll x = accumulate(ALL(L), 0LL);
    sort(ALL(R), greater<ll>());
    REP(i, 0, K - 1) x += R[i];
    x++;
    cout << x << "\n";

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

