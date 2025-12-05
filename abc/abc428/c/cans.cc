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

  vector<pll> vec;
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      char c; cin >> c;
      if (vec.empty()) {
        if (c == '(') vec.emplace_back(1, 0);
        else vec.emplace_back(-1, -1);
      }else {
        auto [vsum, vmin] = vec.back();
        if (c == '(') vec.emplace_back(vsum + 1, min(vmin, vsum + 1));
        else          vec.emplace_back(vsum - 1, min(vmin, vsum - 1));
      }
    }else if (tp == 2) {
      vec.pop_back();
    }else assert(0);
    bool b;
    if (vec.empty()) b = true;
    else {
      auto [vsum, vmin] = vec.back();
      b = vsum == 0 and vmin >= 0;
    }
    cout << (b ? "Yes\n" : "No\n");

  }

  return 0;
}

