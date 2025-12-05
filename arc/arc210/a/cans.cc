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

  ll N, Q; cin >> N >> Q;
  // @InpMVec(Q, ((I, dec=1), X)) [kXOiQpnc]
  auto I = vector(Q, ll());
  auto X = vector(Q, ll());
  for (int i = 0; i < Q; i++) {
    ll v1; cin >> v1; v1 -= 1; I[i] = v1;
    ll v2; cin >> v2; X[i] = v2;
  }
  // @End [kXOiQpnc]

  vector<ll> D(N + 1, 1LL);
  REPrev(_q, Q - 1, 0) {
    ll i = I[_q];
    ll x = X[_q];
    D[i + 1] += x;
    D[i] = max(1LL, D[i] - x);
  }
  ll cur = 0;
  ll ans = 0;
  REP(i, 0, N) {
    cur += D[i];
    ans += cur;
  }
  cout << ans << endl;
  return 0;
}

