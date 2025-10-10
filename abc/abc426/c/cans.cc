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
  vector<ll> cnt(N);
  REP(i, 0, N) cnt[i] = 1;
  ll base = -1;
  REP(_q, 0, Q) {
    ll x, y; cin >> x >> y; x--; y--;
    if (x > base) {
      ll ans = 0;
      REP(i, base + 1, x + 1) {
        ans += cnt[i];
        cnt[y] += cnt[i];
        cnt[i] = 0;
      }
      base = x;
      cout << ans << "\n";
    }else {
      cout << 0 << "\n";
    }
  }

  return 0;
}

