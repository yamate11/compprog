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

  ll N, L; cin >> N >> L;
  // @InpVec(N - 1, D) [xbVwNVVK]
  auto D = vector(N - 1, ll());
  for (int i = 0; i < N - 1; i++) { ll v; cin >> v; D[i] = v; }
  // @End [xbVwNVVK]

  if (L % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }
  ll L3 = L / 3;
  vector<ll> P(L);
  ll t = 0;
  P[0] = 1;
  REP(i, 0, N - 1) {
    t = (t + D[i]) % L;
    P[t]++;
  }
  ll ans = 0;
  REP(i, 0, L3) {
    ll cur = P[i] * P[i + L3] * P[i + 2 * L3];
    ans += cur;
  }
  cout << ans << endl;

  return 0;
}

