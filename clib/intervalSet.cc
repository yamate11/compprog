#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  Interval Set

  The name might be misleading.  What is implemented here is managing
  a function f : [LLONG_MIN, LLONG_MAX) -> T; assuming that a same value tends to
  continue.  Thus, the data structure is a map<ll, T>.  
  ((x0, t0), (x1, t1), ..., (xn, tn)), where x0 == LLONG_MIN and xn == LLONG_MAX, means that for x \in [x_i, x_{i+1})
  the value of f(x) is t_i.
  It is guaranteed that t_i != t_{i + 1}  (for i + 1 < n)

  For interval set in the original meaning, use its characteristic function.

  API:

  template<typename T>
  itv_set(T t = T())  ... constant function f(x) = t for x \in [LLONG_MIN, LLONG_MAX)
  
  void put(ll x, T t) ... f(x) := t
  void put(ll l, ll r, T t) ...  f(x) := t for x \in [l, r)
  void put_at_end(ll y, T t) ... f(x) := t for x >= y.  y must be the largest defined point (except for LLONG_MAX) 
  T get_val(ll x) ... returns f(x)
  pair<ll, ll> get_itvl(ll x) ... returns (y1, y2) where y1 <= x < y2 and y1 and y2 are defined point
  pair<ll, pair<ll, ll>> get(ll x) ... returns (t, (y1, y2)) where f(x) = t and y1 <= x < y2 and y1 and y2 are defined point.

  template<typename x_t, typename y_t, typename res_t, typename f_t>
  itv_set<res_t> itv_apply(f_t f, const itv_set<x_t>& x, const itv_set<y_t>& y)
       // Meaning  ... ret(i) := f(x(i), y(i))
       // Usage ...    auto res = itv_apply<x_t, y_t, res_t, decltype(f)>(f, x, y);
 */

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- intervalSet.cc

template<typename T>
struct itv_set_cell {
};

template<typename T>
struct itv_set {
  
  auto get_iter(ll x) {
    auto it = impl.upper_bound(x);
    return std::prev(it);
  }

  auto get_iter(ll x) const {
    auto it = impl.upper_bound(x);
    return std::prev(it);
  }

  auto divide(ll x) {
    auto it_nxt = impl.upper_bound(x);
    auto it = std::prev(it_nxt);
    if (it->first == x) return it;
    return impl.emplace_hint(it_nxt, x, it->second);
  }

  map<ll, T> impl;  // impl always has (LLONG_MIN, *) and (LLONG_MAX, *) as centinels.

  itv_set(const T& t = T()) {
    impl[LLONG_MIN] = t;
    impl[LLONG_MAX] = T();
  }

  void put(ll l, ll r, const T& t) {
    if (l >= r) throw runtime_error("itv_set.put: l >= r");
    if (l == LLONG_MIN) throw runtime_error("itv_set.put: l == LLONG_MIN");
    if (r == LLONG_MAX) throw runtime_error("itv_set.put: l == LLONG_MAX");
    auto it0 = divide(l);
    auto it1 = divide(r);
    it0->second = t;
    for (auto it = std::next(it0); it != it1; it = impl.erase(it));
    auto it2 = std::prev(it0);
    if (it0->second == it1->second) impl.erase(it1);
    if (it2->second == it0->second) impl.erase(it0);
  }

  void put(ll x, const T& t) { put(x, x + 1, t); }

  void put_at_end(ll x, const T& t) {
    auto it2 = std::prev(impl.end());
    auto it1 = std::prev(it2);
    if (it1->second != t) impl.emplace_hint(it2, x, t);
  }

  const T& get_val(ll x) const { return get_iter(x)->second; }

  pair<ll, ll> get_itvl(ll x) {
    auto it = impl.upper_bound(x);
    return {std::prev(it)->first, it->first};
  }

  pair<T, pair<ll, ll>> get(ll x) {
    auto it = impl.upper_bound(x);
    return {std::prev(it)->second, {std::prev(it)->first, it->first}};
  }

};

template<typename x_t, typename y_t, typename res_t, typename f_t>
itv_set<res_t> itv_apply(f_t f, const itv_set<x_t>& x, const itv_set<y_t>& y) {
  auto itx = x.impl.begin();
  auto ity = y.impl.begin();
  itv_set<res_t> ret(f(itx->second, ity->second));
  auto itcc = ret.impl.begin();
  auto itce = std::next(itcc);
  while (true) {
    ll t;
    tie(t, itx, ity) = [&]() -> tuple<ll, decltype(itx), decltype(ity)> {
      auto nitx = std::next(itx);
      auto nity = std::next(ity);
      if      (nitx->first <  nity->first) return {nitx->first, nitx,  ity};
      else if (nitx->first >  nity->first) return {nity->first,  itx, nity};
      else if (nitx->first < LLONG_MAX)    return {nitx->first, nitx, nity};
      else                                 return {-1,          nitx, nity};
    }();
    if (t == -1) break;
    res_t ncur = f(itx->second, ity->second);
    if (ncur != itcc->second) itcc = ret.impl.emplace_hint(itce, t, move(ncur));
  }
  return ret;
}

// @@ !! END ---- intervalSet.cc

