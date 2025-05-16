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

  ll N, M, Q; cin >> N >> M >> Q;
  vector pall(N, false);
  vector peach(N, set<ll>());
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll x, y; cin >> x >> y; x--; y--;
      peach[x].insert(y);
    }else if (tp == 2) {
      ll x; cin >> x; x--;
      pall[x] = true;
    }else if (tp == 3) {
      ll x, y; cin >> x >> y; x--; y--;
      if (pall[x] or peach[x].contains(y)) {
        cout << "Yes\n";
      }else {
        cout << "No\n";
      }
    }else assert(0);
  }

  return 0;
}

