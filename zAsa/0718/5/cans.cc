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

// @@ !! LIM(wavelet debug)

// ---- inserted library file wavelet.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/wavelet.cc

struct BitVector {
  ll N;
  ll vsize;
  vector<int> vs;
  vector<u64> vb;
  bool built;
  BitVector() = default;
  BitVector(ll N_) : N(N_), vsize((N + 63) / 64), vs(vsize + 1), vb(vsize), built(false) {}
  void set(bool val, int k) {
    if (built) throw runtime_error("already built.");
    if (val) vb[k >> 6] |=   1ULL << (k & 63);
    else     vb[k >> 6] &= ~(1ULL << (k & 63));
  }
  bool at(ll k) { return static_cast<bool>(vb[k >> 6] >> (k & 63) & 1); }
  void build() {
    if (not built) {
      for (ll i = 0; i < vsize; i++) vs[i + 1] = vs[i] + popcount(vb[i]);
      built = true;
    }
  }
  ll rank(bool val, ll k) {
    if (not built) build();
    ll cnt1 = (k >= N) ? vs.back() : vs[k >> 6] + popcount(vb[k >> 6] & ((1ULL << (k & 63)) - 1));
    if (val) return cnt1;
    else     return k - cnt1;
  }

  // for debugging
  vector<bool> vec_view() {
    vector<bool> vec(N);
    for (ll i = 0; i < N; i++) vec[i] = at(i);
    return vec;
  }

};

template<typename INT=ll>
struct WaveletMatrix {
  ll N;
  ll ht;
  vector<BitVector> vbv;
  vector<int> mid;

  pair<bool, INT> _h_rest(ll h, INT t) { return {t >> h & 1, t & ((static_cast<INT>(1) << h) - 1)}; }

  WaveletMatrix() = default;
  WaveletMatrix(const auto& vec, ll amax) { _init(vec, amax); }
  void _init(const auto& vec, ll amax) {
    if (amax < 0) amax = vec.empty() ? 1 : *max_element(vec.begin(), vec.end());
    N = ssize(vec);
    ht = bit_width((u64)amax);
    vbv = vector(ht, BitVector(N));
    mid = vector<int>(ht);
    vector tmpA{vec, vector<INT>(N)};
    vector tmpB(2, vector<INT>(N));
    vector<ll> a{N, 0};
    vector<ll> b{0, 0};
    for (ll h = ht - 1; h >= 0; h--) {
      for (int e = 0; e < 2; e++) {
        for (ll i = 0; i < a[e]; i++) {
          auto [x, y] = _h_rest(h, tmpA[e][i]);
          vbv[h].set(x, e == 0 ? i : a[0] + i);
          tmpB[x][b[x]++] = y;
        }
      }
      mid[h] = b[0];
      swap(tmpA, tmpB);
      a = b;
      b[0] = b[1] = 0;
    }
  }
  
  pair<ll, ll> _next_range(bool x, ll l, ll r, ll h) {
    return {x * mid[h] + vbv[h].rank(x, l), x * mid[h] + vbv[h].rank(x, r)};
  }

  // vec[p]
  INT access(ll p) {
    INT ret = 0;
    for (ll h = ht - 1; h >= 0; h--) {
      bool x = vbv[h].at(p);
      if (x == 1) ret |= INT(1) << h;
      if (x == 0) p =          vbv[h].rank(0, p);
      else        p = mid[h] + vbv[h].rank(1, p);
    }
    return ret;
  }

  // #{ i < r : vec[i] == t }
  ll rank(INT t, ll r) {
    if (bit_width((u64)t) > ht) return 0;
    ll l = 0;
    for (ll h = ht - 1; h >= 0; h--) {
      ll x = t >> h & 1;
      tie (l, r) = _next_range(x, l, r, h);
    }
    return r - l;
  }

  // k-th smallest value in vec[l, r)   (0-indexed)
  INT kth_smallest(ll k, ll l, ll r) {
    if (k < 0 or k >= r - l) throw runtime_error("k out of range");
    INT ret = 0;
    for (ll h = ht - 1; h >= 0; h--) {
      ll num0 = vbv[h].rank(0, r) - vbv[h].rank(0, l);
      bool x = k >= num0;
      if (x) {
        k -= num0;
        ret |= INT(1) << h;
      }
      tie(l, r) = _next_range(x, l, r, h);
    }
    return ret;
  }

  // k-th largest value in vec[l, r)   (0-indexed)
  INT kth_largest(ll k, ll l, ll r) { return kth_smallest(r - l - 1 - k, l, r); }

  // #{ i \in [l, r) : vec[i] < hi }
  ll range_freq(INT hi, ll l, ll r) {
    if (bit_width((u64)hi) > ht) return r - l;
    ll ret = 0;
    for (ll h = ht - 1; h >= 0; h--) {
      ll x = hi >> h & 1;
      if (x == 1) ret += vbv[h].rank(0, r) - vbv[h].rank(0, l);
      tie(l, r) = _next_range(x, l, r, h);
    }
    return ret;
  }

  // #{i \in [l, r) : lo <= vec[i] < hi }
  ll range_freq(INT lo, INT hi, ll l, ll r) { return range_freq(hi, l, r) - range_freq(lo, l, r); }


};



// ---- end wavelet.cc

// ---- inserted function f:<< from util.cc


// If a struct T has member function "string show() const",
// (1) operator<< is defined
// (2) g_show(const T&) is defined.
// g_show is also defined for integral and floating point types and string.


// Declartion of g_show

// If T has member function show(), it is used:

template<typename T>
concept HasShow = requires(const T& t) {
  { t.show() } -> convertible_to<string>;
};

template<class T>
concept Streamable = requires(ostream& os, const T& x) {
  os << x;
};

//   The declaration must be put before calling it.

template<class T>
string g_show(const T& x);

// Definition of g_show_impl
//    The separation between g_show and g_show_impl is needed for order independence.

template<HasShow T> string g_show_impl(const T& t) { return t.show(); }

// basic types

inline string g_show_impl(char c) { return string(1, c); }
inline string g_show_impl(const char* s) { return s ? string(s) : string("(null)"); }
inline string g_show_impl(bool b) { return b ? "true" : "false"; }

// int, ll, ...; note that this also is applied to "sigend/unsigned char"
template<integral T>
  requires (not same_as<T, bool> and not same_as<T, char>)
string g_show_impl(T t) { return to_string(t); }

// double, long double, ...
template<floating_point T> string g_show_impl(T t) { return to_string(t); }

// containers in the standard library

//    pair
template <typename T1, typename T2>
string g_show_impl(const pair<T1,T2>& p) { return "(" + g_show(p.first) + ", " + g_show(p.second) + ")"; }

//    tuple
template<class... Ts>
string g_show_impl(const tuple<Ts...>& t) {
  string s = "(";
  bool first = true;
  apply([&](const auto&... xs) {
    ((s += (first ? "" : ", "), first = false, s += g_show(xs)),
     ...);
  }, t);
  s += ")";
  return s;
}

//   vector, array, deque, (un)ordered set, multiset, (un)ordered map, 

template<typename T, bool pair=false>
string g_show_with_iterator(const T& v) {
  string ret = "[";
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) ret += ", ";
    if constexpr (pair) ret += "(" + g_show(it->first) + ": " + g_show(it->second) + ")";
    else                ret += g_show(*it);
  }
  ret += "]";
  return ret;
}

template<typename T>
string g_show_impl(const vector<T>& v) { return g_show_with_iterator(v); }

template <typename T, size_t N>
string g_show_impl(const array<T, N>& v) { return g_show_with_iterator(v); }

template <typename T, typename C>
string g_show_impl(const set<T, C>& v) { return g_show_with_iterator(v); }

template <typename T, typename C>
string g_show_impl(const unordered_set<T, C>& v) { return g_show_with_iterator(v); }

template <typename T, typename C>
string g_show_impl(const multiset<T, C>& v) { return g_show_with_iterator(v); }

template <typename T, typename T2>
string g_show_impl(const deque<T, T2>& v) { return g_show_with_iterator(v); }

template <typename T1, typename T2, typename C>
string g_show_impl(const map<T1, T2, C>& v) {
  return g_show_with_iterator<map<T1, T2, C>, true>(v);
}

template <typename T1, typename T2, typename C>
string g_show_impl(const unordered_map<T1, T2, C>& v) {
  return g_show_with_iterator<unordered_map<T1, T2, C>, true>(v);
}

//   queue, priority-queue

template<typename T>
string g_show_queue_and_like(const T& v0, auto front_like) {
  T v = v0;  // copy
  string ret = "[";
  bool first = true;
  while (not v.empty()) {
    if (not first) ret += ", ";
    first = false;
    const auto& x = front_like(v);
    ret += g_show(x);
    v.pop();
  }
  ret += "]";
  return ret;
}

template <typename T, typename T2>
string g_show_impl(const queue<T, T2>& v) {
  return g_show_queue_and_like(v, [](const queue<T, T2>& vv) { return vv.front(); });
}

template <typename T, typename T2, typename T3>
string g_show_impl(const priority_queue<T, T2, T3>& v) {
  return g_show_queue_and_like(v, [](const priority_queue<T, T2, T3>& vv) { return vv.top(); });
}

//    optional
template <typename T>
string g_show_impl(const optional<T>& t) { return t ? g_show(*t) : "(nullopt)"; }

//    (signed/unsigned) __int128
//    operator<< is defined here, and the next section makes g_show

ostream& operator<<(ostream& ostr, unsigned __int128 x) {
  if (x == 0) return ostr << "0";
  string s;
  while (x > 0) {
    int d = x % 10;
    s.push_back('0' + d);
    x /= 10;
  }
  reverse(s.begin(), s.end());
  return ostr << s;
}

ostream& operator<<(ostream& ostr, __int128 x) {
  if (x >= 0) {
    return ostr << (unsigned __int128)x;
  } else {
    unsigned __int128 ux = (unsigned __int128)x;
    ux = ~ux + 1;
    return ostr << "-" << ux;
  }
}

template<class T>
string g_show(const T& x) {
  if constexpr (requires { g_show_impl(x); }) {
    return g_show_impl(x);
  } else if constexpr (Streamable<T> && (not HasShow<T>)) {
    ostringstream oss;
    oss << x;
    return oss.str();
  }else {
    static_assert(sizeof(T) == 0, "g_show: unsupported type");
  }
}

// HasGShow
template<typename T>
concept HasGShow = requires(const T& t) {
  { g_show(t) } -> convertible_to<string>;
};

// ---- end f:<<

// ---- inserted library file debug.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/debug.cc
// https://github.com/yamate11/compprog-clib/blob/master/debug.cc

template<class T>
void dbgPrintOne(const T& x) {
  if constexpr (HasGShow<T>) {
    cerr << g_show(x);
  } else {
    cerr << x;
  }
}

inline void dbgLog(bool with_nl) {
  if (with_nl) cerr << endl;
}

template <class Head, class... Tail>
void dbgLog(bool with_nl, Head&& head, Tail&&... tail) {
  dbgPrintOne(head);
  if constexpr (sizeof...(tail) > 0) {
    cerr << " ";
    dbgLog(with_nl, forward<Tail>(tail)...);
  } else {
    if (with_nl) cerr << endl;
  }
}

string dbgTrim(string s) {
  int l = 0, r = (int)s.size();
  while (l < r && isspace((unsigned char)s[l])) l++;
  while (l < r && isspace((unsigned char)s[r - 1])) r--;
  return s.substr(l, r - l);
}

vector<string> dbgSplitNames(const string& s) {
  vector<string> res;
  string cur;
  int depth = 0;

  for (char c : s) {
    if (c == '(' || c == '[' || c == '{') depth++;
    if (c == ')' || c == ']' || c == '}') depth--;

    if (c == ',' && depth == 0) {
      res.push_back(dbgTrim(cur));
      cur.clear();
    } else {
      cur += c;
    }
  }

  res.push_back(dbgTrim(cur));
  return res;
}

template<class T>
void dbgLogKOne(const string& name, T&& value) {
  cerr << name << "=";
  dbgPrintOne(forward<T>(value));
}

template<class... Args>
void dbgLogK(const char* names_c, Args&&... args) {
  vector<string> names = dbgSplitNames(names_c);

  int idx = 0;
  auto print_one = [&](auto&& x) {
    if (idx > 0) cerr << " ";
    if (idx < (int)names.size()) {
      dbgLogKOne(names[idx], forward<decltype(x)>(x));
    } else {
      cerr << "?= ";
      dbgPrintOne(forward<decltype(x)>(x));
    }
    idx++;
  };

  (print_one(forward<Args>(args)), ...);
  cerr << endl;
}

template<class Label, class... Args>
void dbgLogKL(Label&& label, const char* names_c, Args&&... args) {
  dbgPrintOne(forward<Label>(label));
  if constexpr (sizeof...(Args) > 0) cerr << " ";

  vector<string> names = dbgSplitNames(names_c);

  int idx = 0;
  auto print_one = [&](auto&& x) {
    if (idx > 0) cerr << " ";
    if (idx < (int)names.size()) {
      dbgLogKOne(names[idx], forward<decltype(x)>(x));
    } else {
      cerr << "?=";
      dbgPrintOne(forward<decltype(x)>(x));
    }
    idx++;
  };

  (print_one(forward<Args>(args)), ...);
  cerr << endl;
}

#if DEBUG
  #define DLOG(...)        dbgLog(true, __VA_ARGS__)
  #define DLOGNNL(...)     dbgLog(false, __VA_ARGS__)
  #define DCALL(func, ...) func(__VA_ARGS__)
  #define DLOGK(...)       dbgLogK(#__VA_ARGS__, __VA_ARGS__)
  #define DLOGKL(lab, ...) dbgLogKL(lab, #__VA_ARGS__, __VA_ARGS__)
#else
  #define DLOG(...)
  #define DLOGNNL(...)
  #define DCALL(func, ...)
  #define DLOGK(...)
  #define DLOGKL(lab, ...)
#endif

#if DEBUG_LIB
  #define DLOG_LIB   DLOG
  #define DLOGK_LIB  DLOGK
  #define DLOGKL_LIB DLOGKL
#endif

// ---- end debug.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  // @InpVec(N, C) [hKGfdxd2]
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
  // @End [hKGfdxd2]
  vector<ll> P(N);
  {
    vector<ll> W(N + 1, -1LL);
    REP(i, 0, N) {
      P[i] = W[C[i]] + 1;
      W[C[i]] = i;
    }
  }
  DLOGK(P);
  WaveletMatrix wm(P, -1);
  REP(_q, 0, Q) {
    ll l, r; cin >> l >> r; l--;
    cout << wm.range_freq(l + 1, l, r) << "\n";
  }
  
  return 0;
}

