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

  ll N, M; cin >> N >> M;
  using ev_tp = tuple<ll, ll, ll>;
  vector<ev_tp> ev;
  ll START = 1;
  ll COIN = 2;
  ll END = 3;
  REP(i, 0, N) {
    ll x, c; cin >> x >> c;
    ev.emplace_back(x, COIN, c);
  }
  REP(i, 0, M) {
    ll l, r; cin >> l >> r;
    ev.emplace_back(l, START, -1);
    ev.emplace_back(r, END, -1);
  }
  ranges::sort(ev);

  ll ans = 0;
  ll lev = 0;
  for (auto [_z, kd, y] : ev) {
    if (kd == COIN) {
      if (lev > 0) ans += y;
    }else if (kd == START) {
      lev++;
    }else if (kd == END) {
      lev--;
    }else assert(0);
  }
  cout << ans << endl;

  return 0;
}

