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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, D; cin >> N >> D;
  vector<pll> RL;
  REP(i, 0, N) {
    ll l, r; cin >> l >> r; l--;
    RL.emplace_back(r, l);
  }
  sort(ALL(RL));
  ll cnt = 0;
  ll border = 0;
  for (auto [r, l] : RL) {
    if (l < border) continue;
    border = r - 1 + D;
    cnt++;
  }
  cout << cnt << endl;

  return 0;
}

