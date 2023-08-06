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

  multiset<ll> cands;
  multiset<ll> xs;

  auto my_erase = [&](auto it1, auto it2) -> void { cands.erase(cands.find(*it1 ^ *it2)); };

  ll Q; cin >> Q;
  REP(q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll x; cin >> x;
      auto it1 = xs.lower_bound(x);
      auto it2 = make_reverse_iterator(it1);
      if (it1 != xs.end()) cands.insert(x ^ *it1);
      if (it2 != xs.rend()) cands.insert(x ^ *it2);
      if (it1 != xs.end() and it2 != xs.rend()) my_erase(it1, it2);
      xs.insert(x);
    }else if (tp == 2) {
      ll x; cin >> x;
      auto it = xs.lower_bound(x);
      auto it1 = next(it);
      auto it2 = make_reverse_iterator(it);
      if (it1 != xs.end()) my_erase(it, it1);
      if (it2 != xs.rend()) my_erase(it, it2);
      if (it1 != xs.end() and it2 != xs.rend()) cands.insert(*it1 ^ *it2);
      xs.erase(it);
    }else if (tp == 3) {
      cout << *cands.begin() << "\n";
    }else assert(0);
  }

  return 0;
}

