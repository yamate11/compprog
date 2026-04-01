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
  using ev_t = pll;
  vector<ev_t> ev;
  ll END = 0;
  ll START = 1;
  REP(i, 0, N) {
    ll s, e; cin >> s >> e;
    ev.emplace_back(s, START);
    ev.emplace_back(e, END);
  }
  ranges::sort(ev);
  ll vmax = 0;
  ll cur = 0;
  for (auto [t, kd] : ev) {
    if (kd == START) cur++;
    else if (kd == END) cur--;
    else assert(0);
    vmax = max(vmax, cur);
  }
  cout << vmax << endl;
  return 0;
}

