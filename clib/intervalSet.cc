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
struct itv_set {
  
  auto get_it(ll x) {
    if (x < l0 or r0 < x) throw runtime_error("itv_set.get_it: out of range");
    auto it = repl.upper_bound(x);
    return std::prev(it);
  }

  auto get_it(ll x) const {
    if (x < l0 or r0 <= x) throw runtime_error("itv_set.get_it: out of range");
    auto it = repl.upper_bound(x);
    return std::prev(it);
  }

  auto divide(ll x) {
    auto it = get_it(x);
    if (it->first == x) return it;
    auto& [y, t] = *it;
    auto [it2, rc] = repl.emplace(x, t);
    assert(rc);
    return it2;
  }

  ll l0;
  ll r0;
  map<ll, T> repl;  // repl always has (LLONG_MIN, *) and (LLONG_MAX, *) as centinels.

  itv_set(ll l0_, ll r0_, const T& t) : l0(l0_), r0(r0_) {
    repl[LLONG_MIN] = t;
    repl[LLONG_MAX] = T();
    repl[l0] = t; repl[r0] = t;
  }
  itv_set(ll l0_, const vector<T>& vec) : l0(l0_), r0(l0_ + (ll)vec.size()) {
    repl[LLONG_MIN] = vec[0];
    repl[LLONG_MAX] = T();
    for (int i = 1; i < (int)vec.size(); i++) {
      repl[l0 + i] = vec[i];
    }
    repl[r0] = vec[0];
  }

  void put(ll x, T t) {
    divide(x + 1);
    auto it = divide(x);
    it->second = t;
  }

  void put(ll l, ll r, T t) {
    auto it1 = divide(l);
    auto it2 = divide(r);
    auto it = it1;
    it->second = t;
    for (it++; it != it2; it = repl.erase(it));
  }

  T get(ll x) const {
    auto it = get_it(x);
    return it->second;
  }

  vector<tuple<ll, ll, T>> get(ll l, ll r) const {
    vector<tuple<ll, ll, T>> ret;
    auto it = get_it(l);
    ll l1 = l;
    while (true) {
      auto it2 = next(it);
      if (r <= it2->first) {
        ret.emplace_back(l1, r, it->second);
        return ret;
      }
      ret.emplace_back(l1, it2->first, it->second);
      it = it2;
      l1 = it->first;
    }
  }

  tuple<ll, ll, T> get_itv(ll x) const {
    auto it = get_it(x);
    auto it2 = next(it);
    return {max(l0, it->first), min(r0, it2->first), it->second};
  }

  void normalize() {
    auto it = repl.begin();
    while (true) {
      auto itX = std::next(it);
      while (true) {
        if (itX == repl.end()) return;
        if (it->second != itX->second) break;
        itX = repl.erase(itX);
      }
      it = itX;
    }
  }

  void update(auto upd, const itv_set& o) {
    if (l0 != o.l0 or r0 != o.r0) throw runtime_error("itv_set.apply: the intervals do not match.");
    auto itO = o.repl.begin();
    auto itT = repl.begin();
    while (itO->first < LLONG_MAX) {
      /*
      DLOGK(itT->first, itO->first);
      DLOGKL("before", repl);
      DLOGKL("after ", repl);
      */
      if (std::next(itO)->first < std::next(itT)->first) {
        auto it_nxt = divide(std::next(itO)->first);
        upd(itT->second, itO->second);
        itT = it_nxt;
        itO++;
      }else if (std::next(itO)->first > std::next(itT)->first) {
        upd(itT->second, itO->second);
        itT++;
      }else { // std::next(itO)->first == std::next(itT)->first
        upd(itT->second, itO->second);
        itT++;
        itO++;
      }
    }
  }
};

// @@ !! END ---- intervalSet.cc

