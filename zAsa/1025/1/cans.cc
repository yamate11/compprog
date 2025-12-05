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

  ll N, Q; cin >> N >> Q;
  vector<ll> vec(N + 1);
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    ll x; cin >> x;
    if (tp == 1) {
      vec[x] += 1;
    }else if (tp == 2) {
      vec[x] += 2;
    }else if (tp == 3) {
      if (vec[x] >= 2) {
        cout << "Yes\n";
      }else {
        cout << "No\n";
      }
    }
  }

  return 0;
}

