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

// @@ !! LIM(debug random)

// ---- inserted function f:<< from util.cc

// declarations

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p);

template <typename T1, typename T2, typename T3>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3>& t);

template <typename T1, typename T2, typename T3, typename T4>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4>& t);

template <typename T1, typename T2, typename T3, typename T4, typename T5>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4,T5>& t);

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v);

template <typename T, typename C>
ostream& operator<< (ostream& os, const set<T, C>& v);

template <typename T, typename C>
ostream& operator<< (ostream& os, const unordered_set<T, C>& v);

template <typename T, typename C>
ostream& operator<< (ostream& os, const multiset<T, C>& v);

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const map<T1, T2, C>& mp);

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const unordered_map<T1, T2, C>& mp);

template <typename T, typename T2>
ostream& operator<< (ostream& os, const queue<T, T2>& orig);

template <typename T, typename T2>
ostream& operator<< (ostream& os, const deque<T, T2>& orig);

template <typename T, typename T2, typename T3>
ostream& operator<< (ostream& os, const priority_queue<T, T2, T3>& orig);

template <typename T>
ostream& operator<< (ostream& os, const stack<T>& st);

#if __cplusplus >= 201703L
template <typename T>
ostream& operator<< (ostream& os, const optional<T>& t);
#endif

ostream& operator<< (ostream& os, int8_t x);

// definitions

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

template <typename T1, typename T2, typename T3, typename T4, typename T5>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4, T5>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ", " << get<3>(t) << ", " << get<4>(t) << ")";
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

// ---- inserted library file random.cc


struct Random {
  static random_device the_random_device;
  mt19937_64 rng;

  Random() : rng(the_random_device()) {}
  Random(unsigned seed) : rng(seed) {}
  
  ll range(ll i, ll j) {
    if (i >= j) {
      throw runtime_error("Random.range: invalid range");
    }
    uniform_int_distribution<ll> dist(i, j - 1);
    return dist(rng);
  }

};

random_device Random::the_random_device;

// ---- end random.cc

// @@ !! LIM -- end mark --

struct bit_dict {
  bool _built;
  int _size;
  vector<u64> _data;
  vector<int> _summary;  // _summary[i + 1] = Number of ones in [0, 64*i)

  pair<int, int> _dec_idx(int i) const { return { i / 64, i % 64 }; }

  void _init(int _size_, bool val = false) {
    _built = false;
    _size = _size_;
    int dsize = (_size + 63) / 64;
    _data.resize(dsize, val ? ~0 : 0);
    if (val and _size % dsize > 0) _data[dsize - 1] = (1ULL << (_size % dsize)) - 1;
    _summary.resize(dsize + 1);
  }

  bit_dict(int _size_ = 0) { _init(_size_); }
  bit_dict(const auto& v) {
    _init(v.size());
    for (int i = 0; i < (int)(v.size()); i++) set(i, v[i]);
  }
  bit_dict(const bit_dict& o) : _built(o._built), _size(o._size), _data(o._data), _summary(o._summary) {}
  bit_dict(bit_dict&& o) : _built(o._built), _size(o._size), _data(move(o._data)), _summary(move(o._summary)) {}
  
  template<typename X>
  bit_dict& _assign(X&& o) {
    _built = forward<X>(o)._built;
    _size = forward<X>(o)._size;
    _data = forward<X>(o)._data;
    _summary = forward<X>(o)._summary;
    return *this;
  }
  bit_dict& operator=(const bit_dict& o) { return _assign(o); }
  bit_dict& operator=(bit_dict&& o) { return _assign(move(o)); }

  void build() {
    _built = true;
    for (int i = 0; i < ssize(_data); i++) _summary[i + 1] = _summary[i] + popcount(_data[i]);
  }

  void set(int i, bool val = true) {
#if DEBUG
    if (_built) throw runtime_error("bit_dict::set: already built");
#endif
    auto [x, y] = _dec_idx(i);
    if (val) { _data[x] |= 1ULL << y; }
    else { _data[x] &= ~(1ULL << y); }
  }

  bool access(int i) const {
#if DEBUG
    if (not _built) throw runtime_error("bit_dict::access: not yet built");
#endif
    auto [x, y] = _dec_idx(i);
    return _data[x] >> y & 1;
  }

  // Number of ones in [0, i)
  int rank_1(int i) const {
#if DEBUG
    if (not _built) throw runtime_error("bit_rank::access: not yet built");
#endif
    auto [x, y] = _dec_idx(i);
    int ret = _summary[x];
    if (x < ssize(_data)) ret += popcount(_data[x] & ((1ULL << y) - 1));
    return ret;
  }

  // Number of zeroes in [0, i)
  int rank_0(int i) const { return i - rank_1(i); }

  
  int _select(int k, bool val) const {
    auto tot_num = [&]() -> int {
      int r = _summary.back();
      return val ? r : _size - r;
    };
    auto upto_m_byte = [&](int m) -> int {
      return val ? _summary[m] : 64 * m - _summary[m];
    };
    auto upto_m_bit = [&](u64 x, int m) -> int {
      int r = popcount(x & ((1ULL << m) - 1));
      return val ? r : m - r;
    };

    if (k < 0 or k >= tot_num()) return -1;
    int l = 0;
    int r = ssize(_data);
    while (l + 1 < r) {
      int m = (l + r) / 2;
      if (k < upto_m_byte(m)) r = m;
      else l = m;
    }
    // DLOGK(k, tot_num(), l, _summary[l], _summary, _size);
    k -= upto_m_byte(l);
    u64 x = _data[l];
    // DLOGK(k, x, popcount(x));
    int bl = 0;
    int br = 64;
    while (bl + 1 < br) {
      int m = (bl + br) / 2;
      if (k < upto_m_bit(x, m)) br = m;
      else bl = m;
    }
    // DLOGK(bl);
    return l * 64 + bl;
  }

  // Index of the k-th one.  Returns -1 if not exists.
  int select_1(int k) const { return _select(k, 1); }

  // Index of the k-th zero.  Returns -1 if not exists.
  int select_0(int k) const { return _select(k, 0); }

};

struct wavelet {
  ll _bitsize;
  ll _dsize;
  vector<bit_dict> _bds;
  vector<int> _num_zeroes;
  unordered_map<u64, int> _init_idx;
  
  wavelet(const auto& vec, int bitsize = 64) : _bitsize(bitsize) { _init(vec); }

  void _init(const auto& vec) {
    _dsize = ssize(vec);
    _bds.resize(_bitsize);
    _num_zeroes.resize(_bitsize);
    vector<int> ord(_dsize);
    iota(ord.begin(), ord.end(), 0);
    for (int i = 0; i < _bitsize; i++) {
      int j = _bitsize - 1 - i;
      vector<int> tmp(_dsize);
      for (int k = 0; k < _dsize; k++) { tmp[k] = vec[ord[k]] >> j & 1; }
      _bds[i] = bit_dict(tmp);
      _bds[i].build();
      auto prev_ord = ord;
      ord = vector<int>();
      for (int u = 0; u < _dsize; u++) if (not tmp[u]) ord.push_back(prev_ord[u]);
      _num_zeroes[i] = ssize(ord);
      for (int u = 0; u < _dsize; u++) if (    tmp[u]) ord.push_back(prev_ord[u]);
    }
    // DLOGK(_num_zeroes);
    for (int u = 0; u < _dsize; u++) {
      if (u == 0 or vec[ord[u]] != vec[ord[u - 1]]) _init_idx[vec[ord[u]]] = u;
    }
  }

  // Returns orig[idx]
  u64 access(int idx) {
    u64 ret = 0;
    for (int i = 0; i < _bitsize; i++) {
      int j = _bitsize - 1 - i;
      bool b = _bds[i].access(idx);
      if (not b) idx = _bds[i].rank_0(idx);
      else {
        idx = _num_zeroes[i] + _bds[i].rank_1(idx);
        ret |= 1ULL << j;
      }
    }
    return ret;
  }

  // Returns #{i < idx | orig[i] = t}
  int rank(u64 t, int idx) {
    auto it = _init_idx.find(t);
    if (it == _init_idx.end()) return 0;
    for (int i = 0; i < _bitsize; i++) {
      int j = _bitsize - 1 - i;
      bool b = t >> j & 1;
      if (not b) {
        idx = _bds[i].rank_0(idx);
      }else {
        idx = _num_zeroes[i] + _bds[i].rank_1(idx);
      }
    }
    return idx - it->second;
  }

  // Returns idx s.t. orig[idx] = t and #{i < idx | orig[i] = t} = k
  //   i.e. the index of the k-th occurence of t (0-indexed)
  //   or -1 if not exists
  int select(u64 t, int k) {
    auto it = _init_idx.find(t);
    if (it == _init_idx.end()) return -1;
    int idx = it->second + k;
    if (idx >= _dsize) return -1;
    for (int i = _bitsize - 1; i >= 0; i--) {
      int j = _bitsize - 1 - i;
      bool b = t >> j & 1;
      if (not b) {
        idx = _bds[i].select_0(idx);
      }else {
        idx = _bds[i].select_1(idx - _num_zeroes[i]);
      }
      if (not (0 <= idx and idx < _dsize)) return -1;
    }
    return idx;
  }

  // Returns the r-th least value (0-indexed) in the range [s, e).
  u64 quantile(int s, int e, int r) {
    u64 ret = 0;
    for (int i = 0; i < _bitsize; i++) {
      int j = _bitsize - 1 - i;
      int r0s = _bds[i].rank_0(s), r0e = _bds[i].rank_0(e);
      int r1s = s - r0s, r1e = e - r0e;
      bool b = (r0e - r0s) <= r;
      if (not b) {
        s = r0s;
        e = r0e;
      }else {
        s = _num_zeroes[i] + r1s;
        e = _num_zeroes[i] + r1e;
        r -= (r0e - r0s);
        ret |= 1ULL << j;
      }
    }
    return ret;
  }

  // Returns the top k occurrences
  //   i.e. the first (at most) k elements of sorted_in_second({(t, o) | t occurs o times in [s, e)})
  vector<pair<u64, int>> topk(int s, int e, int k) {
    vector<pair<u64, int>> ret;
    using sta = tuple<int, int, int, int, int>;
    priority_queue<sta> pque;
    pque.emplace(e - s, 0, s, e, 0);
    while (not pque.empty()) {
      // DLOGK(pque);
      auto [len, i, lo, hi, t] = pque.top(); pque.pop();
      if (i >= _bitsize) {
        ret.emplace_back(t, len);
        if (ssize(ret) == k) break;
      } else {
        int j = _bitsize - 1 - i;
        int r0s = _bds[i].rank_0(lo), r0e = _bds[i].rank_0(hi);
        int r1s = lo - r0s, r1e = hi - r0e;
        int num0 = r0e - r0s;
        int num1 = r1e - r1s;
        if (num0 > 0) pque.emplace(num0, i + 1, r0s, r0e, t);
        if (num1 > 0) pque.emplace(num1, i + 1, _num_zeroes[i] + r1s, _num_zeroes[i] + r1e, t | (1ULL << j));
      }
    }
    return ret;
  }
};

struct naive_bitdict {
  int _size;
  vector<bool> _data;
  naive_bitdict(int _size_) : _size(_size_), _data(_size_) {}
  naive_bitdict(const vector<bool>& _data_) : _size(ssize(_data_)), _data(_data_) {}
  void set(int i, bool val) { _data[i] = val; }
  bool access(int i) { return _data[i]; }
  int _rank(bool val, int i) {
    int r = 0;
    for (int j = 0; j < i; j++) if (_data[j] == val) r++;
    return r;
  }
  int rank_1(int i) { return _rank(1, i); }
  int rank_0(int i) { return _rank(0, i); }
  int _select(bool val, int k) {
    if (k < 0) return -1;
    for (int i = 0; i < _size; i++) {
      if (_data[i] == val) {
        if (k == 0) return i;
        k--;
      }
    }
    return -1;
  }
  int select_1(int k) { return _select(1, k); }
  int select_0(int k) { return _select(0, k); }
  
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

#if 0
  {
    vector<bool> vb{0, 0, 1, 0, 0, 1, 1, 1, 0, 1};
    bit_dict bd1(10);  // msb 1011100100 lsb
    REP(i, 0, 10) if (vb[i]) bd1.set(i, true);
    bd1.set(0, true);
    bd1.set(0, false);
    bd1.build();
    bit_dict bd2(vb);
    bd2.build();
    naive_bitdict nbd3(vb);
    REP(i, 0, 10) { assert(bd1.access(i) == nbd3.access(i)); }
    REP(i, 0, 10) { assert(bd2.access(i) == nbd3.access(i)); }
    REP(i, 0, 10 + 1) { assert(bd1.rank_1(i) == nbd3.rank_1(i)); }
    REP(i, 0, 10 + 1) { assert(bd1.rank_0(i) == nbd3.rank_0(i)); }
    REP(k, -3, 11) { assert(bd1.select_1(k) == nbd3.select_1(k)); }
    REP(k, -3, 11) { assert(bd1.select_0(k) == nbd3.select_0(k)); }
    bit_dict bd3(bd2);
    REP(i, 0, 10) { assert(bd3.access(i) == nbd3.access(i)); }
    bit_dict bd4(move(bd3));
    REP(i, 0, 10) { assert(bd4.access(i) == nbd3.access(i)); }
  }
  {
    Random rand;
    for (int _rep = 0; _rep < 10000; _rep++) {
      int sz = rand.range(1, 300);
      vector<bool> vb(sz);
      REP(i, 0, sz) vb[i] = rand.range(0, 2) == 0;
      bit_dict bd(vb);
      bd.build();
      naive_bitdict nbd(vb);
      for (int _rep2 = 0; _rep2 < 20; _rep2++) {
        int i = rand.range(0, sz);
        assert(bd.access(i) == nbd.access(i));
        i = rand.range(0, sz + 1);
        assert(bd.rank_1(i) == nbd.rank_1(i));
        i = rand.range(0, sz + 1);
        assert(bd.rank_0(i) == nbd.rank_0(i));
        int k = rand.range(-10, sz);
        assert(bd.select_1(k) == nbd.select_1(k));
        k = rand.range(-10, sz);
        int x0 = bd.select_0(k);
        int y0 = nbd.select_0(k);
        if (x0 != y0) {
          DLOGK(vb, k, x0, y0);
          assert(0);
        }else {
          DLOGK("ok", x0, y0);
        }
      }
    }
  }
#endif
  {
    vector<ll> test1{5, 4, 5, 5, 2, 1, 5, 6, 1, 3, 5, 0};
    wavelet wm(test1, 3);
    for (int i = 0; i < 3; i++) {
      string tmp(12, ' ');
      for (int j = 0; j < 12; j++) tmp[j] = wm._bds[i].access(j) ? '1' : '0';
      // DLOGK(i, tmp);
    }
    for (int i = 0; i < 12; i++) {
      // DLOGK(i, wm.access(i));
    }
    for (int t = 0; t < 8; t++) {
      for (int i = 0; i < 13; i++) {
        // DLOGK(t, i, wm.rank(t, i));
        // DLOGK(t, i, wm.select(t, i));
      }
    }
    for (int s = 0; s < 12; s++) {
      for (int e = s + 1; e <= 12; e++) {
        for (int r = 0; r < e - s; r++) {
          // DLOGK(s, e, r, wm.quantile(s, e, r));
        }
      }
    }
    // DLOGK(wm.topk(3, 5, 2));
    for (int s = 0; s < 12; s++) {
      for (int e = s + 1; e <= 12; e++) {
        for (int k = 1; k <= 8; k++) {
          DLOGK(s, e, k, wm.topk(s, e, k));
        }
      }
    }


  }

  return 0;
}

