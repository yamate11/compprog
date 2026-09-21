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

  ll N, M, S, T; cin >> N >> M >> S >> T;
  map<ll, ll> mp;
  REP(i, 0, M) {
    ll p, v; cin >> p >> v;
    mp[p] += v;
  }
  if (S > T) swap(S, T);
  ll ans = 0;
  for (auto [p, v] : mp) {
    if (S <= p and p <= T) ans += v;
  }
  cout << ans << "\n";
  return 0;
}

