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

  ll Q; cin >> Q;
  ll top = 0;
  ll tail = 0;
  vector<ll> vec;
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll l; cin >> l;
      vec.push_back(tail);
      tail += l;
    }else if (tp == 2) {
      top++;
    }else if (tp == 3) {
      ll k; cin >> k;
      cout << vec[top + k - 1] - vec[top] << "\n";
    }
  }

  return 0;
}

