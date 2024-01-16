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

  string SS; cin >> SS;
  deque<char> S;
  for (char c : SS) S.push_back(c);
  bool flipped = false;
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      flipped = not flipped;
    }else {
      ll f; cin >> f;
      char c; cin >> c;
      if ((f == 1) == (not flipped)) S.push_front(c);
      else S.push_back(c);
    }
  }
  if (flipped) reverse(ALL(S));
  REPOUT(i, 0, SIZE(S), S[i], "");

  return 0;
}

