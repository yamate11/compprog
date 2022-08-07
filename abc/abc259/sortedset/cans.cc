#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM(debug f:perfmeas)

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

// ---- inserted function f:perfmeas from util.cc

// For performance measurement.
// Returns seconds from the epoch in double
double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

// ---- end f:perfmeas

// @@ !! LIM -- end mark --

template<typename T>
class SortedSet {
  constexpr static ll BUCKET_RATIO = 50;
  constexpr static ll REBUILD_RATIO = 170;
  /*
  constexpr static ll BUCKET_RATIO = 5;
  constexpr static ll REBUILD_RATIO = 17;
  */

  struct Itr {
    using iterator_category = input_iterator_tag;
    using value_type = T;
    using difference_type = ptrdiff_t;
    using reference = value_type const&;
    using pointer = value_type const*;

    SortedSet& ss;
    size_t idx1;
    size_t idx2;

    Itr(SortedSet& ss_, size_t idx1_, size_t idx2_) : ss(ss_), idx1(idx1_), idx2(idx2_) {}

    bool operator ==(const Itr& o) const { return idx1 == o.idx1 and idx2 == o.idx2; }
    bool operator !=(const Itr& o) const { return idx1 != o.idx1 or  idx2 != o.idx2; }
    reference operator *() const { return ss.buckets[idx1][idx2]; }
    reference operator ->() const { return &ss.buckets[idx1][idx2]; }

    Itr& operator ++() {
      idx2++;
      if (idx2 == ss.buckets[idx1].size()) {
        idx2 = 0;
        idx1++;
      }
      return *this;
    }
    Itr operator ++(int) {
      Itr const tmp(*this);
      ++*this;
      return tmp;
    }

  };

  size_t _size;
  vector<vector<T>> buckets;

  void _build() {
    // DLOG(" *** build *** ");
    // DLOGKL("before", buckets);
    auto old = move(buckets);
    int num_buckets = lround(ceil(sqrt(_size / BUCKET_RATIO)));
    buckets.resize(num_buckets, vector<T>());
    size_t k = _size / num_buckets;
    ll idx1 = 0, idx2 = 0;
    for (auto& bckt : old) {
      ll pos = 0;
      while (true) {
        if (idx1 == num_buckets - 1 or idx2 + bckt.size() - pos < k) {
          copy(bckt.begin() + pos, bckt.end(), back_inserter(buckets[idx1]));
          idx2 += bckt.size() - pos;
          break;
        }else {
          copy(bckt.begin() + pos, bckt.begin() + pos + (k - idx2), back_inserter(buckets[idx1]));
          pos += k - idx2;
          idx1++;
          idx2 = 0;
        }
      }
    }
    // DLOGKL("after", buckets);
  }

  void _build(const auto& vec) {
    _size = vec.size();
    int num_buckets = lround(ceil(sqrt(_size / BUCKET_RATIO)));
    buckets.resize(num_buckets, vector<T>());
    size_t k = _size / num_buckets;
    for (size_t i = 0; i < num_buckets; i++) {
      copy(vec.begin() + i * k, vec.begin() + (i + 1) * k, back_inserter(buckets[i]));
    }
  }

  tuple<bool, size_t, size_t> _find_place(const T& t) const {
    assert(_size > 0);
    // FIXME: binary search is preferable.
    size_t i = 0, j = 0;
    for ( i = 0; i < buckets.size() and buckets[i].back() < t; i++);
    if (i == buckets.size()) return {false, i - 1, buckets[i - 1].size()};
    for ( j = 0; j < buckets[i].size() and buckets[i][j] < t; j++);
    return {buckets[i][j] == t, i, j};
  }

public:

  SortedSet() : _size(0), buckets() {}

  // FIXME: vec shold be a more general collection.
  SortedSet(const vector<T>& vec) {
    auto srt = vec;
    sort(srt.begin(), srt.end());
    _build(srt);
  }
  
  /* FIXME: Yet to be implemented
  SortedSet(const SortedSet& o);
  SortedSet(SortedSet&& o);
  operator =(const SortedSet& o);
  operator =(SortedSet&& o);
  */

  size_t size() const { return _size; }
  bool empty() const { return _size == 0; }

  Itr find(const T& t) {
    if (_size == 0) return end();
    auto [f, idx1, idx2] = _find_place(t);
    if (f) return Itr{*this, idx1, idx2};
    else   return end();
  }

  pair<Itr, bool> insert(const T& t) {
    if (_size == 0) {
      buckets.push_back(vector<T>());
      buckets[0].push_back(t);
      _size = 1;
      return {Itr{*this, 0, 0}, true};
    }
    auto [f, idx1, idx2] = _find_place(t);
    if (f) return {Itr{*this, idx1, idx2}, false};
    auto& bckt = buckets[idx1];
    _size++;
    bckt.resize(bckt.size() + 1);
    copy_backward(bckt.begin() + idx2, bckt.end() - 1, bckt.end());
    bckt[idx2] = t;
    if (bckt.size() > buckets.size() * REBUILD_RATIO) _build();
    return {Itr{*this, idx1, idx2}, true};
  }

  /*
  pair<Itr, bool> insert(T&& t) {
    throw runtime_error("Sorry, not implemented yet.");
  }
  */
  
  size_t erase(const T& t) {
    if (_size == 0) return 0;
    auto [f, idx1, idx2] = _find_place(t);
    if (not f) return 0;
    auto& bckt = buckets[idx1];
    _size--;
    copy(bckt.begin() + idx2 + 1, bckt.end(), bckt.begin() + idx2);
    bckt.resize(bckt.size() - 1);
    if (bckt.size() == 0 and _size > 0) _build();
    return 1;
  }

  Itr begin() { return Itr{*this, 0, 0}; }
  Itr end() { return Itr{*this, buckets.size(), 0}; }

  const vector<vector<T>> debug_inner() const {
    return buckets;
  }

};


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  if (0) {
    set<int> ss;
    SortedSet<int> myss;
    ll N; cin >> N;
    string lab(argv[1]);
    if (lab == "1") {
      double ts1 = get_time_sec();
      REP(i, N) {
        int tp, x; cin >> tp >> x;
        if (tp == 1) ss.insert(x);
        else         ss.erase(x);
      }
      double ts2 = get_time_sec();
      cout << ts2 - ts1 << endl;
    }else if (lab == "2") {
      double ts1 = get_time_sec();
      REP(i, N) {
        int tp, x; cin >> tp >> x;
        if (tp == 1) myss.insert(x);
        else         myss.erase(x);
      }
      double ts2 = get_time_sec();
      cout << ts2 - ts1 << endl;
    }
    return 0;
  }



  random_device rd;
  mt19937 rng(rd());
  auto randrange = [&rng](ll i, ll j) -> ll {
    uniform_int_distribution<ll> dist(i, j - 1);
    return dist(rng);
  };

  {
    SortedSet<int> ss;

    assert(ss.find(1) == ss.end());
    assert(ss.find(10) == ss.end());
    ss.insert(1);
    assert(ss.find(1) != ss.end());
    assert(ss.find(2) == ss.end());
    ss.insert(2);
    auto it = ss.find(2);
    assert(it != ss.end());
    assert(*it == 2);
    ss.erase(1);
    assert(ss.find(1) == ss.end());
  }

  {
    for (ll k = 0; k < 100; k++) {
      SortedSet<int> myss;
      set<int> ss;
      for (ll i = 0; i < 1000; i++) {
        int t = randrange(0, 1000);
        myss.insert(t);
        ss.insert(t);
        assert(myss.size() == ss.size());
        auto it = ss.begin();
        auto myit = myss.begin();
        while (it != ss.end()) {
          assert (*it == *myit);
          it++;
          myit++;
        }
        if (myit != myss.end()) {
          for (int a : ss) DLOGK(a);
          assert(false);
        }
      }
    }
  }

  {
    for (ll k = 0; k < 100; k++) {
      SortedSet<int> myss;
      set<int> ss;
      for (ll i = 0; i < 10000; i++) {
        int t = randrange(0, 1000);
        if (randrange(0, 100) >= 30) {
          myss.insert(t);
          ss.insert(t);
        }else {
          myss.erase(t);
          ss.erase(t);
        }
        assert(myss.size() == ss.size());
        auto it = ss.begin();
        auto myit = myss.begin();
        while (it != ss.end()) {
          assert (*it == *myit);
          it++;
          myit++;
        }
        if (myit != myss.end()) {
          for (int a : ss) DLOGK(a);
          assert(false);
        }
      }
    }
  }

  return 0;
}

