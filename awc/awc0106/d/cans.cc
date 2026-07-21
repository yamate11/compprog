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

// @@ !! LIM(intervalMap)

// ---- inserted library file intervalMap.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/intervalMap.cc

template<typename T>
struct itv_map {
  using value_type = T;
  
  struct Tuple3 {
    ll left;
    ll right;
    T val;
    bool operator==(const Tuple3&) const = default;
  };

  struct Itr {
    using iterator_category = bidirectional_iterator_tag;
    using difference_type = ptrdiff_t;
    using value_type = Tuple3;
    using reference = value_type;
    using pointer = void;

    using impl_iterator = typename map<ll, T>::const_iterator;
    impl_iterator it_impl;
    Itr(impl_iterator it_impl_) : it_impl(it_impl_) {}

    bool operator ==(const Itr& o) const { return it_impl == o.it_impl; }
    bool operator !=(const Itr& o) const { return it_impl != o.it_impl; }
    value_type operator *() const { return value_type(it_impl->first, std::next(it_impl)->first, it_impl->second); }
    Itr& operator ++() { 
      ++it_impl;
      return *this;
    }
    Itr operator ++(int) { return Itr(it_impl++); }
    Itr& operator --() {
      --it_impl;
      return *this;
    }
    Itr operator --(int) { return Itr(it_impl--); }
    ll left() const { return it_impl->first; }
    ll right() const { return std::next(it_impl)->first; }
    const T& val() const { return it_impl->second; }
    Itr prev() const { return Itr(std::prev(it_impl)); }
    Itr next() const { return Itr(std::next(it_impl)); }
  };
  using iterator = Itr;
  using const_iterator = Itr;
  Itr begin() const { return Itr(impl.begin()); }
  Itr end() const { return Itr(prev(impl.end())); }

  map<ll, T> impl;  
  ll lo;
  ll hi;

  itv_map(ll lo_ = -(1LL << 60), ll hi_ = (1LL << 60), const T& t = T()) : lo(lo_), hi(hi_) {
    impl[lo] = t;
    impl[hi] = t;  // the value is just a dummy.
  }

  bool operator==(const itv_map& o) const { return lo == o.lo and hi == o.hi and impl == o.impl; }
  bool operator!=(const itv_map& o) const { return not (*this == o); }

  auto get_iter(ll x) const { return Itr(std::prev(impl.upper_bound(x))); }

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
    if (x < lo or x >= hi) throw runtime_error("intervalSet: out of range: " + to_string(x));
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

  T get_val(ll x) const {
    range_check(x);
    return get_iter(x).val();
  }

  Tuple3 get(ll x) {
    range_check(x);
    return *get_iter(x);
  }

  T sum(ll l0, ll r0) {
    range_check(l0, r0);
    T ret = T();
    ll i = l0;
    while (true) {
      auto [l, r, t] = get(i);
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
  itv_map<res_t> ret(x.lo, x.hi, f(itx->second, ity->second));
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

// ---- end intervalMap.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  // @InpMVec(N, (A, B)) [XAXB0CJW]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
  }
  // @End [XAXB0CJW]
  // @InpVec(Q, X) [mKRallwd]
  auto X = vector(Q, ll());
  for (int i = 0; i < Q; i++) { ll v; cin >> v; X[i] = v; }
  // @End [mKRallwd]

  ll MOUNTAIN = 2;
  ll CLOUD = 1;
  using ev_tp = tuple<ll, ll, ll>;
  vector<ev_tp> ev;
  REP(i, 0, N) ev.emplace_back(A[i], MOUNTAIN, i);
  REP(i, 0, Q) ev.emplace_back(X[i], CLOUD, i);
  ranges::sort(ev, greater<ev_tp>());

  vector<ll> ans(Q);
  ll val = 0;
  itv_map<ll> im(0, N, -1LL);
  for (auto [h, kd, idx] : ev) {
    if (kd == MOUNTAIN) {
      auto [lo0, hi0, t0] = im.get(idx);
      if (t0 >= 0) {
        if (t0 < B[idx]) {
          val += B[idx] - t0;
          im.put(lo0, hi0, B[idx]);
        }
      }else {
        ll lo_n = idx;
        ll hi_n = idx + 1;
        ll t_n = B[idx];
        ll vdiff = B[idx];
        if (idx - 1 >= 0) {
          auto [lo1, hi1, t1] = im.get(idx - 1);
          if (t1 >= 0) {
            lo_n = lo1;
            if (t_n < t1) {
              vdiff -= t_n;
              t_n = t1;
            }else {
              vdiff -= t1;
            }
          }
        }
        if (idx + 1 < N) {
          auto [lo2, hi2, t2] = im.get(idx + 1);
          if (t2 >= 0) {
            hi_n = hi2;
            if (t_n < t2) {
              vdiff -= t_n;
              t_n = t2;
            }else {
              vdiff -= t2;
            }
          }
        }
        im.put(lo_n, hi_n, t_n);
        val += vdiff;
      }
    }else if (kd == CLOUD) {
      ans[idx] = val;
    }
  }
  REPOUT(i, 0, Q, ans[i], "\n");
  return 0;
}

