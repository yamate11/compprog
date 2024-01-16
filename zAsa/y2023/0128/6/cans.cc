#include <bits/stdc++.h>
/*
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
*/
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

  auto solve = []() -> bool {

    ll N; cin >> N;
    vector<pll> vec;
    REP(i, 0, N) {
      string s; cin >> s;
      ll vmin = 0;
      ll c = 0;
      REP(j, 0, SIZE(s)) {
        c += s[j] == '(' ? 1 : -1;
        vmin = min(vmin, c);
      }
      vec.emplace_back(-vmin, c - vmin);
    }
    sort(ALL(vec), [&](pll p1, pll p2) -> bool {
      auto& [a1, b1] = p1;
      auto& [a2, b2] = p2;
      bool inc1 = a1 <= b1;
      bool inc2 = a2 <= b2;
      if (inc1 != inc2) return inc1;
      else if (inc1) return a1 < a2;
      else return b1 > b2;
    });
    ll c = 0;
    for (auto& [a, b] : vec) {
      if (c - a < 0) return false;
      c = c - a + b;
    }
    return c == 0;
  };
  cout << (solve() ? "Yes\n" : "No\n");

  return 0;
}

