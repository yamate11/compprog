#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(binsearch)
// --> binsearch
// ---- inserted library file binsearch.cc

template<typename T>
T binsearch_i(auto check, T yes, T no, T err = (T)1) {
  while (abs(yes - no) > err) {
    T mid = (yes + no) / 2;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

template<typename T>
T binsearch_r(auto check, T yes, T no, T err, bool rel = true) {
  while (abs(yes - no) > err &&
         (!rel || abs(yes - no) > abs(yes) * err)) {
    T mid = (yes + no) / 2.0;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

ll border_with_hint(ll t, auto pred, auto hint) {
  double y = hint(t);
  double d = floor(y);
  double e = ceil(y);
  bool rd = pred(d, t);
  bool re = pred(e, t);
  if (rd && !re) return d;
  if (!rd && re) return e;
  for (ll i = 1; true; i++) {
    bool rd_i = pred(d - i, t);
    if (rd_i && !rd) return d - i;
    if (!rd_i && rd) return d - (i - 1);
    bool re_i = pred(e + i, t);
    if (re_i && !re) return e + i;
    if (!re_i && re) return e + (i - 1);
  }
}

// ---- end binsearch.cc
// @@ !! LIM  -- end mark --


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<ll> vec1 {1, 4, 9, 10, 15, 18, 20};
  ll sz1 = vec1.size();
  ll lim1;
  auto check1 = [&](ll z) { return vec1.at(z) < lim1; };
  lim1 = 10;
  assert(binsearch_i<ll>(check1, -1, sz1) == 2);
  lim1 = 0;
  assert(binsearch_i<ll>(check1, -1, sz1) == -1);
  lim1 = 100;
  assert(binsearch_i<ll>(check1, -1, sz1) == 6);

  vec1 = vector<ll>({20, 18, 15, 10, 9, 4, 1});
  lim1 = 10;
  assert(binsearch_i<ll>(check1, sz1, -1) == 4);
  lim1 = 0;
  assert(binsearch_i<ll>(check1, sz1, -1) == 7);
  lim1 = 100;
  assert(binsearch_i<ll>(check1, sz1, -1) == 0);
  

  assert(binsearch_i<ll>([&](ll x){ return x*x < 20000; }, 0, 20000) == 141);
  assert(binsearch_i<ll>([&](ll x){ return x*x > 20000; }, 20000, 0) == 142);
  {
    vector<double> ts({2, 2e-5, 2e5, 2e19});
    for (double t : ts) {
      auto check = [&](double x) -> bool { return x * x < t; };
      double sq0 = binsearch_r<double>(check, 0.0, max(1.0, t), 1e-10);
      double sq1 = sqrt(t);
      assert (abs(sq0 - sq1) < 1e-9 * max(1.0, abs(sq1)));
    }
    for (double t : ts) {
      if (t > 1e10) continue;
      auto check = [&](double x) -> bool { return x * x < t; };
      double sq0 = binsearch_r<double>(check, 0.0, max(1.0, t), 1e-10, false);
      double sq1 = sqrt(t);
      assert (abs(sq0 - sq1) < 1e-9);
    }
  }
  
  {
    auto sqrt_le_pred = [](ll x, ll t) -> bool { return x * x <= t; };
    auto sqrt_lt_pred = [](ll x, ll t) -> bool { return x * x < t; };
    auto sqrt_hint = [](double x) -> double { return sqrt(x); };
    auto sqrt_hint_inprec1 = [](double x) -> double { return sqrt(x) + 1000; };
    auto sqrt_hint_inprec2 = [](double x) -> double { return sqrt(x) - 1000; };
    ll x = 1'234'567'890;
    assert(border_with_hint(x * x, sqrt_le_pred, sqrt_hint) == x);
    assert(border_with_hint(x * x - 1, sqrt_le_pred, sqrt_hint) == x - 1);
    assert(border_with_hint(x * x, sqrt_lt_pred, sqrt_hint) == x - 1);
    assert(border_with_hint(x * x + 1, sqrt_lt_pred, sqrt_hint) == x);
    assert(border_with_hint(x * x, sqrt_le_pred, sqrt_hint_inprec1) == x);
    assert(border_with_hint(x * x, sqrt_le_pred, sqrt_hint_inprec2) == x);

    assert(border_with_hint(x * x + x, sqrt_le_pred, sqrt_hint) == x);
    assert(border_with_hint(x * x - x, sqrt_le_pred, sqrt_hint) == x - 1);
  }
	 
}
