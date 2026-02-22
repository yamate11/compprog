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

  deque<pll> deq;

  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll c, x; cin >> c >> x;
      deq.emplace_back(c, x);
    }else if (tp == 2) {
      ll k; cin >> k;
      ll ans = 0;
      while (k > 0) {
        auto [c, x] = deq.front(); deq.pop_front();
        ll d = min(c, k);
        k -= d;
        c -= d;
        ans += d * x;
        if (c > 0) deq.emplace_front(c, x);
      }
      cout << ans << "\n";
    }
  }

  return 0;
}

