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

  ll N = 1 << 20;
  set<ll> ss;
  REP(i, 0, N) ss.insert(i);
  vector A(N, -1LL);

  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll t, x; cin >> t >> x;
    ll h = x % N;
    if (t == 1) {
      auto it = ss.lower_bound(h);
      if (it == ss.end()) {
        it = ss.lower_bound(0);
      }
      assert(it != ss.end());
      ll i = *it;
      A[i] = x;
      ss.erase(it);
    }else if (t == 2) {
      cout << A[h] << "\n";
    }else assert(0);
  }

  return 0;
}

