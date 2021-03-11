#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

ll border_with_hint(ll t, auto f, auto P) {
  double y = f(t);
  double d = floor(y);
  double e = ceil(y);
  bool rd = P(d, t);
  bool re = P(e, t);
  if (rd && !re) return d;
  if (!rd && re) return e;
  for (ll i = 1; true; i++) {
    bool rd_i = P(d - i, t);
    if (rd_i && !rd) return d - i;
    if (!rd_i && rd) return d - (i - 1);
    bool re_i = P(e + i, t);
    if (re_i && !re) return e + i;
    if (!re_i && re) return e + (i - 1);
  }
}



int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll a;
  a = border_with_hint(20000,
                       [](double x) -> double { return sqrt(x); },
                       [](ll x, ll t) -> bool { return x * x <= t; });
  cout << a << endl;
  a = border_with_hint(20000,
                       [](double x) -> double { return sqrt(x) + 100; },
                       [](ll x, ll t) -> bool { return x * x <= t; });
  cout << a << endl;
  a = border_with_hint(20000,
                       [](double x) -> double { return sqrt(x) - 100; },
                       [](ll x, ll t) -> bool { return x * x <= t; });
  cout << a << endl;
  a = border_with_hint(20000,
                       [](double x) -> double { return sqrt(x); },
                       [](ll x, ll t) -> bool { return x * x > t; });
  cout << a << endl;
  a = border_with_hint(20000,
                       [](double x) -> double { return sqrt(x) + 100; },
                       [](ll x, ll t) -> bool { return x * x > t; });
  cout << a << endl;
  a = border_with_hint(20000,
                       [](double x) -> double { return sqrt(x) - 100; },
                       [](ll x, ll t) -> bool { return x * x > t; });
  cout << a << endl;

  ll big = 2000000000000000000;
  a = border_with_hint(big,
                       [](double x) -> double { return sqrt(x) - 100; },
                       [](ll x, ll t) -> bool { return x * x > t; });
  cout << a << endl;
  double y = sqrt(big);
  cout << y << endl;

  ll big2 = 1LL << 62;
  ll vmax = LLONG_MIN;
  ll vmin = LLONG_MAX;
  ll amax = 0, amin = 0;
  for (ll i = 0; i < (1LL << 20); i++) {
    ll x = big2 + i;
    double yy = (double)x;
    ll diff = llround(yy) - x;
    if (diff > vmax) {
      vmax = diff;
      amax = i;
    }
    if (diff < vmin) {
      vmin = diff;
      amin = i;
    }
  }
  cout << "vmax = " << vmax << ", amax = " << amax << endl;
  cout << "vmin = " << vmin << ", amin = " << amin << endl;

  return 0;
}
