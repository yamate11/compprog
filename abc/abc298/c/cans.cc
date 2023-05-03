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

  ll lim = 2e5 + 1;

  ll N; cin >> N;
  ll Q; cin >> Q;

  vector<multiset<ll>> num_in_box(N + 1);
  vector<set<ll>> box_with_num(lim);

  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll i, j; cin >> i >> j;
      num_in_box[j].insert(i);
      box_with_num[i].insert(j);
    }else if (tp == 2) {
      ll i; cin >> i;
      for (ll x : num_in_box[i]) cout << x << " ";
      cout << "\n";
    }else if (tp == 3) {
      ll i; cin >> i;
      for (ll x : box_with_num[i]) cout << x << " ";
      cout << "\n";
    }else assert(0);
  }

  return 0;
}

