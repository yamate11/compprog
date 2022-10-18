#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

// @DefStruct(ev, (t, cost), ord=t) [lqjdCzz0]
struct ev_t {
  ll t;
  ll cost;
  ev_t() {}
  ev_t(ll t_, ll cost_) : t(t_), cost(cost_) {}
  friend istream& operator>>(istream& istr, ev_t& t) {
    istr >> t.t >> t.cost;
    return istr;
  }
  bool operator<(const ev_t& o) const {
    if (t < o.t) return true;
    return false;
  }
};
// @End [lqjdCzz0]

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, C; cin >> N >> C;
  vector<ev_t> ev;
  REP(i, 0, N) {
    ll a, b, c; cin >> a >> b >> c;
    ev.emplace_back(a, c);
    ev.emplace_back(b + 1, -c);
  }
  sort(ALL(ev));
  ll prev = 0;
  ll cc = 0;
  ll ans = 0;
  for (auto [t, c] : ev) {
    ans += (t - prev) * min(cc, C);
    cc += c;
    prev = t;
  }
  assert(cc == 0);
  cout << ans << endl;

  return 0;
}

