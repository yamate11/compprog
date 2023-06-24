#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
using pll = pair<ll, ll>;

// @@ !! LIM(intervalSet debug)

// ---- inserted library file intervalSet.cc
#line 46 "/home/y-tanabe/proj/compprog/clib/intervalSet.cc"

template<typename T>
struct itv_set {
  
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

  itv_set(ll lo_, ll hi_, const T& t = T()) : lo(lo_), hi(hi_) {
    impl[lo] = t;
    impl[hi] = t;  // the value is just a dummy.
  }

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

template<typename x_t, typename y_t, typename res_t, typename f_t>
itv_set<res_t> itv_apply(f_t f, const itv_set<x_t>& x, const itv_set<y_t>& y) {
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

// ---- inserted function f:<< from util.cc
template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

template <typename T1, typename T2, typename T3>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ")";
  return os;
}

template <typename T1, typename T2, typename T3, typename T4>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ", " << get<3>(t) << ")";
  return os;
}

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v) {
  os << '[';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << ']';

  return os;
}

template <typename T, typename C>
ostream& operator<< (ostream& os, const set<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T, typename C>
ostream& operator<< (ostream& os, const unordered_set<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T, typename C>
ostream& operator<< (ostream& os, const multiset<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const map<T1, T2, C>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
}

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const unordered_map<T1, T2, C>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
}

template <typename T, typename T2>
ostream& operator<< (ostream& os, const queue<T, T2>& orig) {
  queue<T, T2> que(orig);
  bool first = true;
  os << '[';
  while (!que.empty()) {
    T x = que.front(); que.pop();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
}

template <typename T, typename T2>
ostream& operator<< (ostream& os, const deque<T, T2>& orig) {
  deque<T, T2> que(orig);
  bool first = true;
  os << '[';
  while (!que.empty()) {
    T x = que.front(); que.pop_front();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
}

template <typename T, typename T2, typename T3>
ostream& operator<< (ostream& os, const priority_queue<T, T2, T3>& orig) {
  priority_queue<T, T2, T3> pq(orig);
  bool first = true;
  os << '[';
  while (!pq.empty()) {
    T x = pq.top(); pq.pop();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
}

template <typename T>
ostream& operator<< (ostream& os, const stack<T>& st) {
  stack<T> tmp(st);
  os << '[';
  bool first = true;
  while (!tmp.empty()) {
    T& t = tmp.top();
    if (first) first = false;
    else os << ", ";
    os << t;
    tmp.pop();
  }
  os << ']';
  return os;
}

#if __cplusplus >= 201703L
template <typename T>
ostream& operator<< (ostream& os, const optional<T>& t) {
  if (t.has_value()) os << "v(" << t.value() << ")";
  else               os << "nullopt";
  return os;
}
#endif

ostream& operator<< (ostream& os, int8_t x) {
  os << (int32_t)x;
  return os;
}

// ---- end f:<<

// ---- inserted library file debug.cc
#line 42 "/home/y-tanabe/proj/compprog/clib/debug.cc"
template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

template <class Head>
void dbgLog(bool with_nl, Head&& head) {
  cerr << head;
  if (with_nl) cerr << endl;
}

template <class Head, class... Tail>
void dbgLog(bool with_nl, Head&& head, Tail&&... tail)
{
  cerr << head << " ";
  dbgLog(with_nl, forward<Tail>(tail)...);
}

#if DEBUG
  #define DLOG(...)        dbgLog(true, __VA_ARGS__)
  #define DLOGNNL(...)     dbgLog(false, __VA_ARGS__)
  #define DFMT(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DLOGNNL(...)
  #define DFMT(...)
  #define DCALL(func, ...)
#endif

/*
#if DEBUG_LIB
  #define DLOG_LIB(...)        dbgLog(true, __VA_ARGS__)
  #define DLOGNNL_LIB(...)     dbgLog(false, __VA_ARGS__)
  #define DFMT_LIB(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL_LIB(func, ...) func(__VA_ARGS__)
#else
  #define DLOG_LIB(...)
  #define DFMT_LIB(...)
  #define DCALL_LIB(func, ...)
#endif
*/

#define DUP1(E1)       #E1 "=", E1
#define DUP2(E1,E2)    DUP1(E1), DUP1(E2)
#define DUP3(E1,...)   DUP1(E1), DUP2(__VA_ARGS__)
#define DUP4(E1,...)   DUP1(E1), DUP3(__VA_ARGS__)
#define DUP5(E1,...)   DUP1(E1), DUP4(__VA_ARGS__)
#define DUP6(E1,...)   DUP1(E1), DUP5(__VA_ARGS__)
#define DUP7(E1,...)   DUP1(E1), DUP6(__VA_ARGS__)
#define DUP8(E1,...)   DUP1(E1), DUP7(__VA_ARGS__)
#define DUP9(E1,...)   DUP1(E1), DUP8(__VA_ARGS__)
#define DUP10(E1,...)   DUP1(E1), DUP9(__VA_ARGS__)
#define DUP11(E1,...)   DUP1(E1), DUP10(__VA_ARGS__)
#define DUP12(E1,...)   DUP1(E1), DUP11(__VA_ARGS__)
#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,NAME,...) NAME
#define DUP(...)          GET_MACRO(__VA_ARGS__, DUP12, DUP11, DUP10, DUP9, DUP8, DUP7, DUP6, DUP5, DUP4, DUP3, DUP2, DUP1)(__VA_ARGS__)
#define DLOGK(...)        DLOG(DUP(__VA_ARGS__))
#define DLOGKL(lab, ...)  DLOG(lab, DUP(__VA_ARGS__))

#if DEBUG_LIB
  #define DLOG_LIB   DLOG
  #define DLOGK_LIB  DLOGK
  #define DLOGKL_LIB DLOGKL
#endif

// ---- end debug.cc

// @@ !! LIM -- end mark --
#line 8 "intervalSet_skel.cc"

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  random_device rd;
  mt19937 rng(rd());
  auto randrange = [&rng](ll i, ll j) -> ll {
    uniform_int_distribution<ll> dist(i, j - 1);
    return dist(rng);
  };

  {
    //               0 1 2 3 4 5 6 7 8 91011121314
    vector<int> vec({0,0,1,1,1,0,0,0,0,0,1,0,0,1,1});
    itv_set<int> isA(-10, 20, 0);
    isA.put(2, 1);
    isA.put(3, 1);
    isA.put(4, 1);
    isA.put(10, 1);
    isA.put(13, 1);
    isA.put(14, 1);
    // represents {2,3,4,10,13,14} == [2,5) \cup [10, 11) \cup [13, 15)
    itv_set<int> isB(-10, 20, 0);
    isB.put(2, 5, 1);
    isB.put(10, 11, 1);
    isB.put(13, 15, 1);
    for (ll i = -10; i < 20; i++) assert(isA.get(i) == isB.get(i));
    assert(isA.impl == isB.impl);
    {
      auto it = isA.get_iter(3);
      assert(it->first == 2 and it->second == 1);
    }
    {
      auto it = isA.get_iter(8);
      assert(it->first == 5 and it->second == 0 and next(it)->first == 10);
    }
  }

  {
    itv_set<string> is1(LLONG_MIN, LLONG_MAX);
    is1.put(-40, -20, "hello");
    assert(is1.get_val(100) == "");
    assert(is1.get_val(-40) == "hello");
    assert(is1.get_val(-20) == "");
    itv_set<string> is2(LLONG_MIN, LLONG_MAX, "world");
    is2.put(90, "globe");
    assert(is2.get_val(50) == "world");
    assert(is2.get_val(89) == "world");
    assert(is2.get_val(90) == "globe");
    assert(is2.get_val(91) == "world");
    auto [l, r, _dummy1] = is2.get(90);
    assert(l == 90 and r == 91);
    auto [l2, r2, _dummy2] = is2.get(91);
    assert(l2 == 91 and r2 == LLONG_MAX);
  }
  {
    ll nc = 1000;
    ll sz = 40;
    ll mutL = 10;
    ll mutR = 20;
    ll vmax = sz * 2;
    for (ll i = 0; i < nc; i++) {
      vector<ll> vec(sz);
      itv_set<ll> is(0, sz);
      for (ll j = 0; j < sz; j++) {
        vec[j] = randrange(0, vmax);
        is.put(j, vec[j]);
      }
      ll mut = randrange(mutL, mutR);
      for (ll k = 0; k < mut; k++) {
        ll l = randrange(0, sz);
        ll r = randrange(l + 1, sz + 1);
        ll x = randrange(0, vmax);
        if (k % 2 == 0) {
          is.put(l, r, x);
          for (ll j = l; j < r; j++) vec[j] = x;
        }else {
          is.put(l, x);
          vec[l] = x;
        }
      }
      for (ll j = 0; j < sz; j++) {
        auto [l, r, v] = is.get(j);
        assert(l <= j and j < r and vec[j] == v and vec[j] == is.get_val(j));
      }
      for (auto it = is.impl.begin(); std::next(it)->first < sz; it++) {
        assert(it->second != std::next(it)->second);
      }
      ll prev_r = 0;
      ll prev_t = LLONG_MIN;
      for (const auto& [l, r, t] : is) {
        assert(l == prev_r);
        assert(t != prev_t);
        assert(l < r);
        for (ll k = l; k < r; k++) assert(vec[k] == t);
        prev_r = r;
        prev_t = t;
      }
      assert(prev_r == sz);
    }
  }
  {
    ll nc = 1000;
    ll sz = 40;
    ll mutL = 10;
    ll mutR = 20;
    for (ll i = 0; i < nc; i++) {
      vector<bool> vecA(sz), vecB(sz);
      itv_set<bool> isA(0, sz), isB(0, sz);
      for (ll j = 0; j < sz; j++) {
        vecA[j] = randrange(0, 2) == 0 ? false : true;
        isA.put(j, vecA[j]);
        vecB[j] = randrange(0, 2) == 0 ? false : true;
        isB.put(j, vecB[j]);
      }
      ll mut = randrange(mutL, mutR);
      for (ll k = 0; k < mut; k++) {
        ll l = randrange(0, sz);
        ll r = randrange(l + 1, sz + 1);
        ll x = randrange(0, 2) == 0 ? false : true;
        if (k % 3 == 0) {
          isA.put(l, r, x);
          for (ll j = l; j < r; j++) vecA[j] = x;
        }else if (k % 3 == 1) {
          isB.put(l, r, x);
          for (ll j = l; j < r; j++) vecB[j] = x;
        }else {
          auto ff = [](bool p, bool q) -> bool { return p ^ q; };
          isA = itv_apply<bool, bool, bool, decltype(ff)>(ff, isA, isB);
          for (ll j = 0; j < sz; j++) vecA[j] = vecA[j] ^ vecB[j];
        }
      }
      for (ll j = 0; j < sz; j++) assert(vecA[j] == isA.get_val(j) and vecB[j] == isB.get_val(j));
      for (ll j = 0; j < sz; j++) {
        auto [l, r, v] = isA.get(j);
        assert(l <= j and j < r and vecA[j] == v);
      }
      for (ll j = 0; j < sz; j++) {
        auto [l, r, v] = isB.get(j);
        assert(l <= j and j < r and vecB[j] == v);
      }
      for (auto it = isA.impl.begin(); std::next(it)->first < sz; it++) {
        assert(it->second != std::next(it)->second);
      }
      for (auto it = isB.impl.begin(); std::next(it)->first < sz; it++) {
        assert(it->second != std::next(it)->second);
      }
    }
  }
  {
    itv_set<int> isA(0, 100, 0);
    isA.put(30, 60, 5000);
    isA.put(60, 100, 6000);
    itv_set<int> isB(0, 100, 0);
    isB.put(40, 60, 300);
    isB.put(60, 80, 200);
    isB.put(80, 100, 100);
    auto op = [&](int x, int y) -> int { return x + y; };
    auto isC = itv_apply<int, int, int, decltype(op)>(op, isA, isB);
    itv_set<int> isD(0, 100, 0);
    isD.put(30, 40, 5000);
    isD.put(40, 60, 5300);
    isD.put(60, 80, 6200);
    isD.put(80, 100, 6100);
    assert(isC.impl == isD.impl);
  }

  {
    itv_set<pll> isA(0, 100);
    itv_set<pll> isB(0, 100);
    isA.put(10, 20, pll{3, 4});
    isA.put(20, 30, pll{5, 6});
    isB.put(5, 15, pll{10, 20});
    isB.put(15, 25, pll{30, 40});
    auto myadd = [&](pll p1, pll p2) -> pll { return pll{p1.first + p2.first, p1.second + p2.second}; };
    auto isC = itv_apply<pll, pll, pll, decltype(myadd)>(myadd, isA, isB);
    auto [l, r, t1] = isC.get(12);
    assert(t1 == pll(13, 24) and l == 10 and r == 15);
    assert(isC.get_val(17) == pll(33, 44));
    assert(isC.get(22) == make_tuple(20, 25, pll(35, 46)));
  }
  {
    itv_set<int> is(0, 100, 10);
    is.put(15, 20, 2);
    is.put(25, 30, 1);
    assert(is.sum(10, 15) == 50);
    assert(is.sum(15, 20) == 10);
    assert(is.sum(14, 16) == 12);
    assert(is.sum(12, 32) == 3 * 10 + 5 * 2 + 5 * 10 + 5 * 1 + 2 * 10);
    is.put(27, 27, 1000);
    is.put(27, 25, 2000);
    assert(is.get_val(27) == 1);
    auto [l0, r0, t0] = is.get(27);
    assert(l0 == 25 and r0 == 30);
  }

  cout << "ok\n";
}
