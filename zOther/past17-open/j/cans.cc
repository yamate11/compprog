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
  enum kind { ARRIVE, ASK, LEAVE };
  using ev_t = tuple<ll, kind, ll>;
  vector<ev_t> ev;
  REP(i, 0, N) {
    ll a, b; cin >> a >> b;
    ev.emplace_back(a, ARRIVE, 0);
    ev.emplace_back(b, LEAVE, 0);
  }
  ll Q; cin >> Q;
  REP(i, 0, Q) {
    ll t; cin >> t;
    ev.emplace_back(t, ASK, i);
  }
  sort(ALL(ev));
  vector<ll> ans(Q);
  ll cnt = 0;
  for (auto [t, k, i] : ev) {
    if (k == ARRIVE) cnt++;
    else if (k == LEAVE) cnt--;
    else if (k == ASK) ans[i] = cnt;
    else assert(0);
  }
  REPOUT(i, 0, Q, ans[i], "\n");

  return 0;
}

