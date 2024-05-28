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

  ll N; cin >> N;
  enum en_t { OPEN, CLOSE };
  using sta = pair<ll, en_t>;
  vector<sta> ev;
  REP(i, 0, N) {
    ll l, r; cin >> l >> r;
    ev.emplace_back(l, OPEN);
    ev.emplace_back(r, CLOSE);
  }
  sort(ALL(ev));
  ll ans = 0;
  ll opened = 0;
  for (auto [t, e] : ev) {
    if (e == OPEN) {
      ans += opened;
      opened++;
    }else if (e == CLOSE) {
      opened--;
    }else assert(0);
  }
  cout << ans << endl;
  return 0;
}

