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

  auto solve = [&]() -> void {
    ll N; cin >> N;
    string s0, s1; cin >> s0 >> s1;
    vector<ll> tbl(N + 1);
    tbl[0] = 0;
    if (s0[0] == s1[0]) tbl[1] = 0;
    else tbl[1] = 1;
    REP(i, 2, N + 1) {
      if (s0[i - 1] == s1[i - 1]) tbl[i] = tbl[i - 1];
      else tbl[i] = tbl[i - 1] + 1;
      ll cnt = 0;
      if (s0[i - 2] != s0[i - 1]) cnt++;
      if (s1[i - 2] != s1[i - 1]) cnt++;
      tbl[i] = min(tbl[i], tbl[i - 2] + cnt);
    }
    cout << tbl[N] << "\n";

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

