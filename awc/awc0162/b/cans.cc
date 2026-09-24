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

  ll N, X; cin >> N >> X;
  vector<pll> AB(N);
  REP(i, 0, N) {
    ll a, b; cin >> a >> b;
    AB[i] = pll(a, b);
  }
  ranges::sort(AB, greater<pll>());
  ll prev = X;
  ll ans = 0;
  for (auto [a, b] : AB) {
    if (not (a < prev)) continue;
    if (b <= 0) continue;
    ans += b;
    prev = a;
  }
  cout << ans << "\n";

  return 0;
}

