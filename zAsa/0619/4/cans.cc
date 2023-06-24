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

  ll L, Q; cin >> L >> Q;
  set<ll> marks;
  marks.insert(0);
  marks.insert(L);
  REP(_q, 0, Q) {
    ll c, x; cin >> c >> x;
    if (c == 1) {
      marks.insert(x);
    }else if (c == 2) {
      auto it = marks.lower_bound(x);
      ll u = *it;
      it--;
      ll l = *it;
      cout << u - l << "\n";
    }else assert(0);
  }

  return 0;
}

