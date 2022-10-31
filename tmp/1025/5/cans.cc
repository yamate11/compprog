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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  using sta = tuple<double, ll, ll>;
  priority_queue<sta, vector<sta>, greater<sta>> pque;
  string S; cin >> S;
  enum {TH_N, TH_C, DMG, BACK, REL_PROH};
  REP(i, 0, SIZE(S)) {
    if (S[i] == 'N') pque.emplace(i, TH_N, 0);
    else if (S[i] == 'C') pque.emplace(i, TH_C, 0);
  }
  ll combo = 0;
  ll stock = 5;
  bool prohib = false;
  ll dmg = 0;
  while (not pque.empty()) {
    auto [tm, tp, param] = pque.top(); pque.pop();
    if (tp == TH_N) {
      if (prohib) continue;
      if (stock < 1) continue;
      stock -= 1;
      pque.emplace(tm + 1.5, DMG, 1 * (10 + (combo / 10)));
      pque.emplace(tm + 6.5, BACK, 1);
    }else if (tp == TH_C) {
      if (prohib) continue;
      if (stock < 3) continue;
      stock -= 3;
      prohib = true;
      pque.emplace(tm + 2.5, REL_PROH, 0);
      pque.emplace(tm + 3.5, DMG, 5 * (10 + (combo / 10)));
      pque.emplace(tm + 8.5, BACK, 3);
    }else if (tp == DMG) {
      dmg += param;
      combo += 1;
    }else if (tp == BACK) {
      stock += param;
    }else if (tp == REL_PROH) {
      prohib = false;
    }
  }
  cout << dmg << endl;

  return 0;
}

