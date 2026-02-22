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

  ll Q, A, B; cin >> Q >> A >> B;
  set<ll> ss;
  ss.insert(A + B);
  ss.insert(A - B);
  REP(_q, 0, Q) {
    ll t, a, b; cin >> t >> a >> b;
    if (t == 1) {
      ss.insert(a + b);
      ss.insert(a - b);
    }else if (t == 2) {
      auto ita = ss.lower_bound(a);
      auto itb = ss.lower_bound(b);
      ll vmin = 0;
      if (ita != itb) {
        vmin = 0;
      }else {
        ll big = LLONG_MAX;
        ll xa, xb;
        if (ita == ss.end()) { xb = big; }
        else { xb = *ita - b; }
        if (ita == ss.begin()) { xa = big; }
        else { xa = a - *prev(ita); }
        vmin = min(xa, xb);
      }
      cout << vmin << "\n";
    }
  }

  return 0;
}

