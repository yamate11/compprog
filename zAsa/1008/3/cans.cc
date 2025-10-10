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

  string S; cin >> S;
  deque<char> S0;
  for (char c : S) S0.push_back(c);
  ll Q; cin >> Q;
  bool swapped = false;
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      swapped = not swapped;
    }else if (tp == 2) {
      ll f; cin >> f;
      char c; cin >> c;
      if (swapped == (f == 1)) S0.push_back(c);
      else                     S0.push_front(c);
    }
  }
  if (swapped) reverse(ALL(S0));
  string ans;
  for (char c : S0) ans += c;
  cout << ans << endl;

  return 0;
}

