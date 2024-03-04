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
  string S; cin >> S;
  vector pos(26, vector(0, 0LL));
  REP(i, 0, N) pos[S[i] - 'a'].push_back(i);
  vector pos2(0, pair<ll, ll>());
  REPrev(c, 25, 0) for (ll p : pos[c][p]) pos2.emplace_back(p, c);
  ll r = N;
  REP(i, 0, N) {
    if ([&]() -> bool {
      while (not pos2.empty()) {
        if (pos2.back().second >= S[i] - 'a') return false;
        else if (pos2.back().first >= r or pos2.back().first <= i) pos2.pop_back();
        else return true;
      }
    }()) {
      r = pos2.back().first;
      pos2.pop_back();
      swap(s[i], s[r]);
    }
  }
  return 0;
}

