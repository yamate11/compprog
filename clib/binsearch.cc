#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  Binary Search

  Usage:
    auto check = [&](ll x) -> bool { return true or false; };
    ll ans = binsearch_i<ll>(check, yes, no);

    auto check2 = [&](double x) { return true or false; };
    double ans2 = binsearch_r<double>(check, yes, no, 1e-9, true);

  binsearch_i() (for int/ll/...)  and binsearch_r() (for
  double/long double/...) returns the boundary value ans such that
  check(ans) == true and check(ans +/- err) == false.
  The default value for err is 1 for binsearch_i
  should be suitable for long long and int.
  The fifth argument for binsearch_r controls whether relative err
  is also checked (default is true).

 */

/*
  Border with Hint

  Usage:
    auto pred = [](ll x, ll t) -> bool { return true or false; }
    auto hint = [](double x) -> double { return some_value; }
    ll x = ....;
    ll ans = border_with_hint(x, pred, hint);
          // returns ans such that 
          // pred(x, ans) == true and pred(x, ans') == false,
          // where ans' == ans + 1 or ans' == ans - 1,
          // using hint, i.e. abs(ans - hint(x)) is small.

  E.g.  
    ll a = border_with_hint(20000,
                            [](ll x, ll t) -> bool { return x * x <= t; }
                            [](double x) -> double { return sqrt(x); });
    // a == 141
 */


//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN()  ---- binsearch.cc

template <typename T>
requires integral<T>
T binsearch(auto check, T yes, T no) {
  while (abs(no - yes) > 1) {
    T mid = yes + (no - yes) / 2;  // avoiding unnecessary overflow
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

template <typename T>
requires floating_point<T>
T binsearch(auto check, T yes, T no, T err) {
  int rep = llround(ceil(log(abs(yes - no) / err) / log(2.0))) + 1;
  for (int r = 0; r < rep; r++) {
    T mid = (yes + no) / 2.0;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

// @@ !! END  ---- binsearch.cc

