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

  ll N, K, Q; cin >> N >> K >> Q;
  set<pll> lo;
  set<pll> hi;
  ll vLo = 0, vHi = 0;
  vector<ll> belong(N);
  vector<ll> val(N);
  REP(i, 0, N - K) {
    lo.emplace(0, i);
    belong[i] = 0;
  }
  REP(i, N - K, N) {
    hi.emplace(0, i);
    belong[i] = 1;
  }
  REP(_q, 0, Q) {
    ll x, y; cin >> x >> y; x--;
    if (belong[x] == 0) {
      auto it = lo.find(pll(val[x], x));
      vLo = vLo - val[x];
      lo.erase(it);
      lo.emplace(y, x);
      vLo = vLo + y;
      val[x] = y;
    }else {
      auto it = hi.find(pll(val[x], x));
      vHi = vHi - val[x];
      hi.erase(it);
      hi.emplace(y, x);
      vHi = vHi + y;
      val[x] = y;
    }
    if (SIZE(lo) > 0 and SIZE(hi) > 0) {
      auto itLo = prev(lo.end());
      auto itHi = hi.begin();
      auto [vlo, ilo] = *itLo;
      auto [vhi, ihi] = *itHi;
      if (vlo > vhi) {
        lo.emplace(vhi, ihi);
        hi.emplace(vlo, ilo);
        lo.erase(itLo);
        hi.erase(itHi);
        vLo = vLo - vlo + vhi;
        vHi = vHi - vhi + vlo;
        belong[ilo] = 1;
        belong[ihi] = 0;
      }
    }
    cout << vHi << endl;
  }


  return 0;
}

