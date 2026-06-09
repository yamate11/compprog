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
  deque<char> d;
  for (char c : S) d.push_back(c);
  bool reversed = false;
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      reversed = not reversed;
    }else if (tp == 2) {
      ll f; cin >> f;
      char c; cin >> c;
      if (f == 1) {
        if (reversed) d.push_back(c);
        else d.push_front(c);
      }else if (f == 2) {
        if (reversed) d.push_front(c);
        else d.push_back(c);
      }
    }
  }
  if (reversed) ranges::reverse(d);
  for (char c : d) cout << c;
  cout << endl;

  return 0;
}

