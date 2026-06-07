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

// @@ !! LIM(sortedIndex intervalSet)

// ---- inserted library file sortedIndex.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/sortedIndex.cc

template<typename INT = long long int>
vector<INT> sortedIndex(const auto& vec, auto comp) {
  vector<INT> ret(vec.size());
  iota(ret.begin(), ret.end(), (INT)0);
  sort(ret.begin(), ret.end(), [&vec, &comp](INT i, INT j) { return comp(vec[i], vec[j]); });
  return ret;
}

template<typename INT = long long int>
pair<vector<INT>, vector<INT>> sortedIndex2(const auto& vec, auto comp) {
  auto ord2idx = sortedIndex(vec, comp);
  vector<INT> idx2ord(vec.size());
  for (size_t i = 0; i < vec.size(); i++) idx2ord[ord2idx[i]] = i;
  return {move(ord2idx), move(idx2ord)};
}

template<typename INT = long long int, typename Collection>
vector<INT> sortedIndex(const Collection& vec) {
  return sortedIndex<INT>(vec, less<typename Collection::value_type>());
}

template<typename INT = long long int, typename Collection>
pair<vector<INT>, vector<INT>> sortedIndex2(const Collection& vec) {
  return sortedIndex2<INT>(vec, less<typename Collection::value_type>());
}


// ---- end sortedIndex.cc

// ---- inserted library file intervalSet.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/intervalSet.cc

template<typename T>
struct itv_set {
  using value_type = T;
  
  struct Itr {
    using iterator_category = input_iterator_tag;
    using value_type = tuple<ll, ll, const T&>;
    // using difference_type = ptrdiff_t;
    using reference = value_type const&;
    // using pointer = value_type const*;

    using impl_iterator = typename map<ll, T>::iterator;
    impl_iterator it_impl;

    Itr(impl_iterator it_impl_) : it_impl(it_impl_) {}

    bool operator ==(const Itr& o) const { return it_impl == o.it_impl; }
    bool operator !=(const Itr& o) const { return it_impl != o.it_impl; }
    value_type operator *() const { return value_type(it_impl->first, (std::next(it_impl))->first, it_impl->second); }
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
    ll right() const { return (std::next(it_impl))->first; }
    const T& val() const { return it_impl->second; }
    Itr prev() const { return Itr(std::prev(it_impl)); }
    Itr next() const { return Itr(std::next(it_impl)); }
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
    return Itr(std::prev(it));
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

  const T& get_val(ll x) {
    range_check(x);
    return get_iter(x).val();
  }

  tuple<ll, ll, const T&> get(ll x) {
    range_check(x);
    return *get_iter(x);
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

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, X; cin >> N >> X;
  // @InpVec(N, T, dec=0) [UvFK5gA7]
  auto T = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 0; T[i] = v; }
  // @End [UvFK5gA7]
  // @InpVec(N, A) [VlZAPbav]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [VlZAPbav]
  auto ord = sortedIndex(A, greater<ll>());

  ll lim = 1e5 + 1;
  itv_set<ll> is(0, lim);
  
  ll gotnum = 0;
  ll gotval = 0;
  REP(ii, 0, N) {
    ll i = ord[ii];
    auto [lo, hi, v] = is.get(T[i]);
    if (v == 0) {
      is.put(T[i], 1);
      gotnum++;
      gotval += A[i];
    }else if (lo == 1) {
      ;
    }else {
      is.put(lo - 1, 1);
      gotnum++;
      gotval += A[i];
    }
    if (gotval >= X) {
      cout << gotnum << "\n";
      return 0;
    }
  }
  cout << -1 << "\n";
  return 0;
}

