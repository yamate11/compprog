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

// @@ !! LIM(intervalSet binsearch)

// ---- inserted library file intervalSet.cc

template<typename T>
struct itv_set {
  using value_type = T;
  
  struct Itr {
    using iterator_category = input_iterator_tag;
    using value_type = tuple<ll, ll, T>;
    // using difference_type = ptrdiff_t;
    using reference = value_type const&;
    // using pointer = value_type const*;

    using impl_iterator = typename map<ll, T>::iterator;
    impl_iterator it_impl;

    Itr(impl_iterator it_impl_) : it_impl(it_impl_) {}

    bool operator ==(const Itr& o) const { return it_impl == o.it_impl; }
    bool operator !=(const Itr& o) const { return it_impl != o.it_impl; }
    value_type operator *() const {
      auto [l, t] = *it_impl;
      auto [r, _dummy] = *(next(it_impl));
      return value_type(l, r, t);
    }
    Itr& operator ++() { 
      ++it_impl;
      return *this;
    }
    Itr operator ++(int) {
      Itr const tmp(*this);
      ++*this;
      return tmp;
    }
  };
  using iterator = Itr;
  Itr begin() { return Itr(impl.begin()); }
  Itr end() { return Itr(prev(impl.end())); }

  map<ll, T> impl;  
  ll lo;
  ll hi;

  itv_set(ll lo_ = LLONG_MIN, ll hi_ = LLONG_MAX, const T& t = T()) : lo(lo_), hi(hi_) {
    impl[lo] = t;
    impl[hi] = t;  // the value is just a dummy.
  }

  bool operator==(const itv_set& o) const { return lo == o.lo and hi == o.hi and impl == o.impl; }
  bool operator!=(const itv_set& o) const { return not (*this == o); }

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

  
  void range_check(ll l, ll r) const {
    if (l < lo or r > hi) throw runtime_error("intervalSet: out of range: " + to_string(l) + ", " + to_string(r));
  }
  void range_check(ll x) const {
    if (x < lo or x > hi - 1) throw runtime_error("intervalSet: out of range: " + to_string(x));
  }

  void put(ll l, ll r, const T& t) {
    range_check(l, r);
    if (l >= r) return;
    auto it0 = divide(l);
    auto it1 = divide(r);
    it0->second = t;
    for (auto it = std::next(it0); it != it1; it = impl.erase(it));
    if (std::next(it1) != impl.end() and it0->second == it1->second) impl.erase(it1);
    if (it0 != impl.begin() and std::prev(it0)->second == it0->second) impl.erase(it0);
  }

  void put(ll x, const T& t) {
    range_check(x);
    put(x, x + 1, t);
  }

  const T& get_val(ll x) const {
    range_check(x);
    return get_iter(x)->second;
  }

  tuple<ll, ll, T> get(ll x) {
    range_check(x);
    auto it = impl.upper_bound(x);
    return {std::prev(it)->first, it->first, std::prev(it)->second};
  }

  T sum(ll l0, ll r0) {
    range_check(l0, r0);
    T ret = T();
    ll i = l0;
    while (true) {
      const auto& [l, r, t] = get(i);
      ret += (min(r, r0) - i) * t;
      if (r0 <= r) return ret;
      i = r;
    }
  }

};

auto itv_apply(auto f, const auto& x, const auto& y) {
  using x_t = typename remove_reference_t<decltype(x)>::value_type;
  using y_t = typename remove_reference_t<decltype(x)>::value_type;
  using res_t = decltype(f(declval<x_t>(), declval<y_t>()));

  if (x.lo != y.lo or x.hi != y.hi) throw runtime_error("intervalSet: range mismatch");
  auto itx = x.impl.begin();
  auto ity = y.impl.begin();
  itv_set<res_t> ret(x.lo, x.hi, f(itx->second, ity->second));
  auto itcc = ret.impl.begin();
  auto itce = std::next(itcc);
  while (true) {
    ll t;
    tie(t, itx, ity) = [&]() -> tuple<ll, decltype(itx), decltype(ity)> {
      auto nitx = std::next(itx);
      auto nity = std::next(ity);
      if      (nitx->first <  nity->first) return {nitx->first, nitx,  ity};
      else if (nitx->first >  nity->first) return {nity->first,  itx, nity};
      else if (nitx->first < x.hi)         return {nitx->first, nitx, nity};
      else                                 return {-1,          nitx, nity};
    }();
    if (t == -1) break;
    res_t ncur = f(itx->second, ity->second);
    if (ncur != itcc->second) itcc = ret.impl.emplace_hint(itce, t, move(ncur));
  }
  return ret;
}

// ---- end intervalSet.cc

// ---- inserted library file binsearch.cc

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
T binsearch(auto check, T yes, T no, T err, const bool abs_only = false) {
  T rep_in_t = ceil(log(abs(yes - no) / err) / log(2.0));
  constexpr int lim = INT_MAX - 10;
  int rep = rep_in_t > (T)lim ? lim : llround(rep_in_t) + 1;
  for (int r = 0; r < rep; r++) {
    T mid = (yes + no) / 2.0;
    if (not abs_only) {
      if (abs(yes - mid) < err * min(abs(mid), abs(yes))) return mid;
    }
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

// ---- end binsearch.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, X) [x52N9bMT]
  auto X = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; X[i] = v; }
  // @End [x52N9bMT]

  ll big = 1e18;
  itv_set<int> itv(-big, big, -1);
  REP(i, 0, N) itv.put(X[i], i);

  auto intersect = [&](ll p1, ll q1, ll p2, ll q2) {
    bool noti = q1 <= p2 or q2 <= p1;
    return not noti;
  };

  auto get_coord = [&](ll t) -> ll {
    auto check = [&](ll x) -> bool {
      ll tt;
      auto [p, q, v] = itv.get(x);
      if (v >= 0) {
        tt = v + x - p;
      }else {
        if (q > big - 10) tt = N;
        else {
          auto [p2, q2, v2] = itv.get(q);
          tt = v2;
        }
      }
      return tt <= t;
    };
    ll x = binsearch<ll>(check, -big + 10, big - 10);
    return x;
  };

  ll ans = 0;
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll t, g; cin >> t >> g; t--;

    ll this_move = 0;
    ll x = get_coord(t);
    if (x < g) {
      auto [lo, hi, _one] = itv.get(x);
      itv.put(x, hi, -1);
      ll new_lo = g, new_hi = g + hi - x;
      this_move += (g - x) * (hi - x);
      while (true) {
        auto [p1, q1, _zero1] = itv.get(x);
        if (q1 > big - 10) break;
        auto [p2, q2, _one2] = itv.get(q1);
        if (not intersect(new_lo, new_hi, p2, q2)) break;
        this_move += (new_hi - p2) * (q2 - p2);
        new_hi += q2 - p2;
        itv.put(p2, q2, -1);
      }
      auto [pp, qq, __d] = itv.get(x);
      ll val;
      if (pp < -big + 10) val = 0;
      else  {
        auto [pp2, qq2, vv] = itv.get(pp - 1);
        val = vv + qq2 - pp2;
      }
      itv.put(new_lo, new_hi, val);
    }else if (g < x) {
      auto [lo, hi, _one] = itv.get(x);
      itv.put(lo, x + 1, 0);
      ll new_hi = g + 1, new_lo = g - (x - lo);
      this_move += (x - g) * (x - lo + 1);
      while (true) {
        auto [p1, q1, _zero1] = itv.get(x);
        if (p1 < -big + 10) break;
        auto [p2, q2, _one2] = itv.get(p1 - 1);
        if (not intersect(new_lo, new_hi, p2, q2)) break;
        this_move += (q2 - new_lo) * (q2 - p2);
        new_lo -= q2 - p2;
        itv.put(p2, q2, 0);
      }
      auto [pp, qq, __d] = itv.get(x);
      ll val;
      if (pp < -big + 10) val = 0;
      else  {
        auto [pp2, qq2, vv] = itv.get(pp - 1);
        val = vv + qq2 - pp2;
      }
      itv.put(new_lo, new_hi, val);
    }
    ans += this_move;
  }
  cout << ans << endl;

  return 0;
}

