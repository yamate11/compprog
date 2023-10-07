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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  ll sz = SIZE(S);
  auto tbl_init = vector(2, vector(2, vector(2, vector(sz + 1, 0LL))));
  auto tbl = tbl_init;
  tbl[1][1][0][0] = 1;
  for (char c : S) {
    ll d = c - '0';
    auto prev = move(tbl);
    tbl = tbl_init;
    REP(eq, 0, 2) REP(az, 0, 2) REP(eff, 0, 2) REP(k, 0, sz + 1) {
      ll t = prev[eq][az][eff][k];
      if (t == 0) continue;
      REP(x, 0, 10) {
        if (eq and x > d) continue;
        ll new_eq = eq and x == d;
        ll new_az = az and x == 0;
        ll new_eff = x == 1 and (eff or az);
        ll new_k = new_eff ? k + 1 : k;
        tbl[new_eq][new_az][new_eff][new_k] += t;
      }
    }
  }
  ll ans = 0;
  REP(eq, 0, 2) REP(eff, 0, 2) REP(k, 0, sz + 1) ans += k * tbl[eq][0][eff][k];
  cout << ans << endl;

  return 0;
}

