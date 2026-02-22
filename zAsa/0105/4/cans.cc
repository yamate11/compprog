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

  ll N, C; cin >> N >> C;
  map<ll, ll> mp;
  REP(i, 0, N) {
    ll a, b, c; cin >> a >> b >> c; a--;
    mp[a] += c;
    mp[b] -= c;
  }
  ll ans = 0;
  ll prev = 0;
  ll cur = 0;
  for (auto [i, v] : mp) {
    ans += (i - prev) * min(cur, C);
    cur += v;
    prev = i;
  }
  cout << ans << endl;
  return 0;
}

