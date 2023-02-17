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

  ll N, Q; cin >> N >> Q;
  vector prev(N + 1, -1LL);
  vector next(N + 1, -1LL);
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll x, y; cin >> x >> y;
      next[x] = y;
      prev[y] = x;
    }else if (tp == 2) {
      ll x, y; cin >> x >> y;
      next[x] = -1LL;
      prev[y] = -1LL;
    }else if (tp == 3) {
      ll x; cin >> x;
      ll p = x;
      vector<ll> rec;
      while (prev[p] >= 0) p = prev[p];
      rec.push_back(p);
      while (next[p] >= 0) {
        p = next[p];
        rec.push_back(p);
      }
      cout << SIZE(rec);
      for (ll t : rec) cout << " " << t;
      cout << "\n";
    }
  }

  return 0;
}

