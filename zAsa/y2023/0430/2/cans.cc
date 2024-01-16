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
  map<ll, set<ll>> ss;
  REP(_q, 0, Q) {
    ll tp, a, b; cin >> tp >> a >> b;
    if (tp == 1) {
      ss[a].insert(b);
    }else if (tp == 2) {
      ss[a].erase(b);
    }else if (tp == 3) {
      if (ss[a].find(b) != ss[a].end() and ss[b].find(a) != ss[b].end()) cout << "Yes\n";
      else cout << "No\n";
    }else assert(0);
  }

  return 0;
}

