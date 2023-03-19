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
  set<ll> s1, s2;
  REP(i, 1, N + 1) s1.insert(i);
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      auto it = s1.begin();
      s2.insert(*it);
      s1.erase(it);
    }else if (tp == 2) {
      ll x; cin >> x;
      s2.erase(x);
    }else if (tp == 3) {
      auto it = s2.begin();
      cout << *it << "\n";
    }else assert(0);
  }
  

  return 0;
}

