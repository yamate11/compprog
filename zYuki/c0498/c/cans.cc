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

  auto ask = [&](ll t) -> pll {
    cout << "? " << t << endl;
    ll x, y; cin >> x >> y;
    return pll(x, y);
  };

  auto report = [&](ll t) -> void {
    cout << "! " << t << endl;
  };


  ll T, x0, y0, xt, yt; cin >> T >> x0 >> y0 >> xt >> yt;
  
  ll tL = 0, tH = T;
  while (true) {
    if (tH == tL + 1) {
      report(tL);
      return 0;
    }
    ll tM = (tL + tH) / 2;
    auto [xM, yM] = ask(tM);
    ll dL = abs(x0 - xM) + abs(y0 - yM);
    ll dH = abs(xt - xM) + abs(yt - yM);
    if (dL == dH) {
      report(tM);
      return 0;
    }
    if (dL > dH) tH = tM;
    else tL = tM;
  }


  return 0;
}

