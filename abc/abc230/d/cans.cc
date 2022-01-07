#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, D; cin >> N >> D;
  vector<ll> L(N), R(N);
  ll START = 1;
  ll END = 0;
  using ev_t = tuple<ll, ll, ll>; // t, ev, idx
  vector<ev_t> ev;
  REP(i, N) {
    ll l, r; cin >> l >> r; l--;
    L[i] = l;
    R[i] = r;
    ev.emplace_back(l, START, i);
    ev.emplace_back(r, END, i);
  }
  sort(ALL(ev));
  ll ans = 0;
  vector<bool> eff(N, true);
  set<ll> cur;
  ll until = -1;
  for (auto& e : ev) {
    auto& [t, tp, idx] = e;
    if (tp == START) {
      if (t < until) eff[idx] = false;
      else           cur.insert(idx);
    }else { // tp == END
      if (eff[idx]) {
        ans++;
        until = t + D - 1;
       eff[idx] = false;
        for (ll j : cur) eff[j] = false;
        cur = set<ll>();
      }
    }
  }
  cout << ans << endl;
  

  return 0;
}

