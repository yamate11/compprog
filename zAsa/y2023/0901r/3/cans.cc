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

  string N; cin >> N;
  ll sz = SIZE(N) + 1;
  auto tbl_init = vector(2, vector(2, vector(2, vector(sz, 0LL))));
  auto tbl = tbl_init;
  tbl[1][1][0][0] = 1;
  for (char c : N) {
    ll d = c - '0';
    auto prev = move(tbl);
    tbl = tbl_init;
    REP(eq, 0, 2) REP(az, 0, 2) REP(ct, 0, 2) REP(val, 0, sz) {
      ll val_prev = prev[eq][az][ct][val];
      if (val_prev == 0) continue;
      REP(x, 0, 10) {
        if (eq and x > d) continue;
        ll new_eq = eq and x == d;
        ll new_az = az and x == 0;
        ll new_ct = (az and x == 1) or (ct and x == 1);
        ll new_val = new_ct ? val + 1 : val;
        tbl[new_eq][new_az][new_ct][new_val] += val_prev;
      }
    }
  }
  ll ans = 0;
  REP(eq, 0, 2) REP(ct, 0, 2) REP(val, 0, sz) ans += tbl[eq][0][ct][val] * val;
  cout << ans << endl;

  return 0;
}

