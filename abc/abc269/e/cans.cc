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

  auto ask = [&](ll x0, ll x1, ll y0, ll y1) -> ll {
    cout << "? " << x0 + 1 << " " << x1 << " " << y0 + 1 << " " << y1 << endl;
    ll t; cin >> t;
    return t;
  };
  auto finans = [&](ll x, ll y) -> void {
    cout << "! " << x + 1 << " " << y + 1 << endl;
  };

  ll N; cin >> N;
  ll x0 = 0, x1 = N, y0 = 0, y1 = N;
  while (x0 + 1 < x1) {
    ll x = (x0 + x1) / 2;
    ll t = ask(x0, x, 0, N);
    if (t < x - x0) x1 = x;
    else x0 = x;
  }
  while (y0 + 1 < y1) {
    ll y = (y0 + y1) / 2;
    ll t = ask(0, N, y0, y);
    if (t < y - y0) y1 = y;
    else y0 = y;
  }
  finans(x0, y0);

  return 0;
}

