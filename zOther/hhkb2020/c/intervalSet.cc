#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  Interval Set

  The name might be misleading.  What is implemented here is managing
  a function f : [l0, r0) -> T; assuming that a same value tends to
  continue.  Thus, the data structure is a map<ll, T>.  
  ((x0, t0), (x1, t1), ..., (xn, tn)) means that for x \in [x0, x1)
  the value of f is t0, for x \in [x1, x2) f(x) = t1, and so on.
  Thus, value tn is a dummy, and x0 == l0 and r0 == xn.

  For interval set in the original meaning, use its characteristic
  function.

  API:

  itv_set(ll l0, ll r0, T t)  ... constant function f(x) = t for x \in [l0, r0)
  itv_set(ll l0, vector<T>&& vec) ... f(l0 + i) := vec[i]
  
  void put(ll x, T t) ... f(x) := t
  void put(ll l, ll r, T t) ...  f(x) := t for x \in [l, r)
  T get(ll x)      ... returns f(x)
  vector<tuple<ll, ll, T>> get(ll l, ll r) 
      ... returns ((x0, x1, t0), (x1, x2, t1), ..., (xn-1, xn, tn-1)) 
          where x0 ==l and xn == r.  
          Note that it might be the case t_i == t_{i+1}.
  tuple<ll, ll, T> get_itv(ll x) ... returns (l, r, f(x)) where x \in [l, r)
  void normalize() ... remove redundant endpoints
  void update(auto upd, const itv_set& o)
      ... upd receives T& and const T& and updates the first argument (and returns nothing).
          This function is executed with each element of *this as the first and that of o as the second parameter.
      e.g. 
      // itv_set<ll> A(...), B(...);
      // auto upd = [&](ll& a, const ll& b) -> void { a += b; };
      // A.update(upd, B);

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
    auto& [_, t] = *it;
    auto [it3, rc] = impl.emplace_hint(it_nxt, x, t);
    assert(rc);
    return it3;
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
    if (it0->second == it1) impl.erase(it1);
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

  pair<ll, pair<ll, ll>> get(ll x) {
    auto it = impl.upper_bound(x);
    return {it->second, {std::prev(it)->first, it->first}};
  }

  template<typename F>
  itv_set apply(F f, itv_set x, itv_set y) {
    auto itx = x.impl.begin();
    auto ity = y.impl.begin();
    itv_set ret(f(itx->second, ity->second));
    auto itcc = ret->impl.begin();
    auto itce = std::next(itcc);
    while (true) {
      ll t;
      tie(t, itx, ity) = [&]() {
        auto nitx = std::next(itx);
        auto nity = std::next(ity);
        if      (nitx->first <  nity->first) return {nitx->first, nitx,  ity};
        else if (nitx->first >  nity->first) return {nity->first,  ity, nitx};
        else if (nitx->first < LLONG_MAX)    return {nitx->first, nitx, nity};
        else                                 return {-1,          nitx, nity};
      }();
      if (t == -1) break;
      T ncur = f(itx->second, ity->second);
      bool dummy;
      if (ncur != itcc->second) tie(itcc, dummy) = ret.impl.emplace_hint(itce, t, move(ncur));
    }
  }
};

// @@ !! END ---- intervalSet.cc

