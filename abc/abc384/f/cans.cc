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

// @@ !! LIM(trie digit debug cmpNaive)

// ---- inserted library file trie.cc

template <int bt_size, char from, typename User = monostate,
  typename S = string, bool compact = 2 < bt_size, bool has_offset = true>
struct Trie {

  Trie* parent = nullptr;

  using c_pat_t = conditional_t<compact, unsigned long long, monostate>;
  [[no_unique_address]] c_pat_t c_pat{};

  using cpt_children_t = conditional_t<compact, vector<Trie*>, monostate>;
  [[no_unique_address]] cpt_children_t cpt_children{};

  using children_t = conditional_t<compact, monostate, array<Trie*, bt_size>>;
  [[no_unique_address]] children_t children{};

  using offset_t = conditional_t<has_offset, int, monostate>;
  static consteval offset_t make_default_offset() {
    if constexpr (is_same_v<offset_t, int>) return -1;
    else return {};
  }
  [[no_unique_address]] offset_t offset = make_default_offset();

  bool reside = false;

  int size_st = 0;

  [[no_unique_address]] User user{};

  Trie() = default;
  Trie(Trie* p, int offset_) : parent(p) {
    if constexpr (has_offset) offset = offset_;
  }

  Trie* get_child_val(int c, bool create = false) { return get_child_offset(c - from, create); }

  Trie* get_child_offset(int d, bool create = false) {
    if constexpr(compact) {
      ll idx = popcount(c_pat & ((1ULL << d) - 1));
      if (c_pat >> d & 1) return cpt_children[idx];
      if (not create) return nullptr;
      Trie* p = new Trie(this, d);
      cpt_children.insert(cpt_children.begin() + idx, p);
      c_pat |= 1ULL << d;
      return p;
    }else {
      Trie* p = children[d];
      if (p) return p;
      if (not create) return nullptr;
      p = children[d] = new Trie(this, d);
      return p;
    }
  }

  struct children_iterator {
    Trie* node;
    int idx;
    int offset;
    explicit children_iterator(Trie* node_, int idx_, int offset_) : node(node_), idx(idx_), offset(offset_) {
      _next_effective_child();
    }
    pair<Trie*, char> operator*() const {
      Trie* p;
      if constexpr (compact) p = node->cpt_children[idx];
      else                   p = node->children[idx];
      return make_pair(p, from + offset);
    }
    void _next_effective_child() {
      if constexpr (compact) {
        if constexpr (has_offset) {
          if (idx < ssize(node->cpt_children)) offset = node->cpt_children[idx]->offset;
          else offset = bt_size;
        }else {
          while (offset < bt_size and not (node->c_pat >> offset & 1)) offset++;
        }
      }else {
        while (idx < bt_size and not node->children[idx]) idx++;
        offset = idx;
      }
    }
    const children_iterator& operator++() {
      idx++;
      offset++;
      _next_effective_child();
      return *this;
    }
    bool operator !=(const children_iterator& o) const { return node != o.node or offset != o.offset; }
  };

  struct children_view {
    Trie* node;
    children_view(Trie* node_) : node(node_) {}
    children_iterator begin() const { return children_iterator(node, 0, 0); }
    children_iterator end() const { return children_iterator(node, bt_size, bt_size); }
  };

  auto children_w_val() { return children_view(this); }

  Trie* get_node(const auto& s, bool create = false) {
    Trie* tr = this;
    for (auto c : s) {
      auto cld = tr->get_child_val(c, create);
      if (not cld) return nullptr;
      tr = cld;
    }
    return tr;
  }
  Trie* get_node(const char* s, bool create = false) { return get_node(string(s), create); }

  Trie* search(const auto& s) {
    Trie* p = get_node(s);
    if (p and not p->reside) p = nullptr;
    return p;
  }
  Trie* search(const char* s) { return search(string(s)); }

  Trie* insert(const auto& s) {
    Trie* tr = get_node(s, true);
    if (not tr->reside) {
      tr->reside = true;
      for (Trie* p = tr; p; p = p->parent) p->size_st++;
    }
    return tr;
  }
  Trie* insert(const char* s) { return insert(string(s)); }

  void erase() {
    if (reside) for (Trie* tr = this; tr; tr = tr->parent) tr->size_st--;
    reside = false;
  }

  int get_offset() {
    if constexpr (has_offset) return offset;
    else {
      Trie* p = parent;
      if (not p) return -1;
      for (int d = 0; d < bt_size; d++) if (p->get_child_offset(d) == this) return d;
      assert(0);
    }
  }

  S repr() {
    S ret;
    for (Trie* tr = this; true; tr = tr->parent) {
      ll d = tr->get_offset();
      if (d < 0) break;
      ret.push_back(from + tr->get_offset());
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }

  void _show_sub(auto& vec) {
    if (reside) vec.push_back(repr());
    for (int i = 0; i < bt_size; i++) {
      Trie* p = get_child_offset(i);
      if (p) p->_show_sub(vec);
    }
  }

  vector<S> show() {
    vector<S> ret;
    _show_sub(ret);
    return ret;
  }


};


// ---- end trie.cc

// ---- inserted library file digit.cc

struct digit_util {
  const ll base;
  const vector<ll> _pow;

  static vector<ll> _make_pow(ll b) {
    vector<ll> ret;
    ll t = 1;
    while (true) {
      ret.push_back(t);
      if (__builtin_smulll_overflow(t, b, &t)) break;
    }
    return ret;
  };

  digit_util(ll base_ = 10) : base(base_), _pow(_make_pow(base_)) {}
    
  ll pow_size() const { return _pow.size(); }
  ll pow(ll i) const {
    if (i < 0 or ssize(_pow) <= i) return -1;
    return _pow[i];
  }

  ll width(ll x) const {
    if (x < 0) return -1;
    if (base == 2) return bit_width((unsigned long long)x);
    if (x == 0) return 0;
    ll ret = 0;
    for (; x != 0; x /= base) ret++;
    return ret;
  }

  ll nd_min(ll i) const { return i < 0 ? -1 : i == 0 ? 0 : pow(i - 1); }
  ll nd_max(ll i) const { return i < 0 ? -1 : i == 0 ? 0 : nd_min(i + 1) - 1; }

  ll floor(ll x) const { return (x < 0) ? -1 : x == 0 ? 0 : _pow[width(x) - 1]; }

  ll ceil(ll x) const {
    if (x < 0) return -1;
    if (x == 0) return 0;
    ll p = _pow[width(x) - 1];
    return (x == p) ? p : (p * base);
  }

  ll log(ll x) const { return (x <= 0) ? -1 : width(x) - 1; }

  ll d_at(ll x, ll i) const {
    if (x < 0) return -1;
    if (x == 0) return 0;
    if (i < 0) i += width(x);
    return (x / pow(i)) % base;
  }

  ll d_sub(ll x, ll pos, ll len) const {
    if (x < 0) return -1;
    if (x == 0) return 0;
    ll w = width(x);
    if (pos < 0) pos += w;
    if (len < 0) { len = -len; pos = pos - len + 1; }
    if (pos < 0) { len += pos; pos = 0; }
    if (pos + len > w) len = w - pos;
    return (x % pow(pos + len)) / pow(pos);
  }

  vector<ll> to_vector(ll x) const {
    if (x < 0) return vector<ll>{};
    if (x == 0) return vector<ll>{0};
    vector<ll> ret;
    ret.reserve(width(x));
    for ( ; x != 0; x /= base) { ret.push_back(x % base); }
    return ret;
  }

  string to_string(ll x, bool upcase = false) const {
    if (x < 0) return string();
    if (x == 0) return string("0");
    char ten = upcase ? 'A' : 'a';
    ll w = width(x);
    string ret(w, ' ');
    for (ll i = w - 1; x != 0; x /= base, i--) {
      ll y = x % base;
      ret[i] = y < 10 ? '0' + y : ten + (y - 10);
    }
    return ret;
  }

  ll from_vector(const vector<ll>& vec) const {
    ll ret = 0;
    for (ll i = 0; i < ssize(vec); i++) ret += vec[i] * pow(i);
    return ret;
  }

  static ll _get_digit_char(char c) {
    if ('0' <= c and c <= '9')      return c - '0';
    else if ('a' <= c and c <= 'z') return c - 'a' + 10;
    else if ('A' <= c and c <= 'Z') return c - 'A' + 10;
    else throw runtime_error("_get_digit_char: unknown letter");
  }

  ll from_string(string s) const {
    ll ret = 0;
    for (ll i = 0; i < ssize(s); i++) ret += _get_digit_char(s[i]) * pow(ssize(s) - 1 - i);
    return ret;
  }


};

// ---- end digit.cc

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

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4,T5,T6>& t);

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v);

template <typename T, size_t N>
ostream& operator<< (ostream& os, const array<T, N>& v);

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

ostream& operator<< (ostream& os, const __int128& x);

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
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4,T5>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ", " << get<3>(t) << ", " << get<4>(t) << ")";
  return os;
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4,T5,T6>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ", " << get<3>(t) << ", " << get<4>(t) << ", " << get<5>(t) << ")";
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

template <typename T, size_t N>
ostream& operator<< (ostream& os, const array<T, N>& v) {
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

// for Enum type; just displays ordinals.
template <typename E>
typename std::enable_if<std::is_enum<E>::value, std::ostream&>::type
operator<<(std::ostream& os, E e) {
    return os << static_cast<typename std::underlying_type<E>::type>(e);
}

// This is a very ad-hoc implementation...
// Known problem: "1 << 127" cannot be handled.
ostream& operator<<(ostream& os, const __int128& v) {
  unsigned __int128 a = v < 0 ? -v : v;
  ll i = 0;
  string s(64, ' ');
  if (v == 0) {
    s[i++] = '0';
  }else {
    while (a > 0) {
      s[i++] = '0' + (char)(a % 10);
      a /= 10;
    }
  }
  if (v < 0) {
    s[i++] = '-';
  }
  s.erase(s.begin() + i, s.end());
  reverse(s.begin(), s.end());
  os << s;
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

// ---- inserted library file cmpNaive.cc

const string end_mark("^__=end=__^");

int naive(istream& cin, ostream& cout);
int body(istream& cin, ostream& cout);

void cmpNaive() {
  while (true) {
    string s;
    getline(cin, s);
    bool run_body;
    if (s.at(0) == 'Q') {
      return;
    }else if (s.at(0) == 'B') {
      run_body = true;
    }else if (s.at(0) == 'N') {
      run_body = false;
    }else {
      cerr << "Unknown body/naive specifier.\n";
      exit(1);
    }
    string input_s;
    while (true) {
      getline(cin, s);
      if (s == end_mark) break;
      input_s += s;
      input_s += "\n";
    }
    stringstream ss_in(move(input_s));
    stringstream ss_out;
    ss_out << setprecision(20);
    if (run_body) {
      body(ss_in, ss_out);
    }else {
      naive(ss_in, ss_out);
    }
    cout << ss_out.str() << end_mark << endl;
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

#if CMPNAIVE
  if (argc == 2) {
    if (strcmp(argv[1], "cmpNaive") == 0) {
      cmpNaive();
    }else if (strcmp(argv[1], "naive") == 0) {
      naive(cin, cout);
    }else if (strcmp(argv[1], "skip") == 0) {
      exit(0);
    }else {
      cerr << "Unknown argument.\n";
      exit(1);
    }
  }else {
#endif
    body(cin, cout);
#if CMPNAIVE
  }
#endif
  return 0;
}

/*
int naive(istream& cin, ostream& cout) {
  return 0;
}
int body(istream& cin, ostream& cout) {
  return 0;
}
*/

// ---- end cmpNaive.cc

// @@ !! LIM -- end mark --

int naive(istream& cin, ostream& cout) {
  ll N; cin >> N;
  // @InpVec(N, A) [OGwogUje]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [OGwogUje]
  ll ans = 0;
  REP(i, 0, N) REP(j, i, N) {
    ll x = A[i] + A[j];
    ll k = countr_zero((u64)x);
    ans += (x >> k);
  }
  cout << ans << endl;

  return 0;
}
int body(istream& cin, ostream& cout) {

  digit_util du2(2);

  ll N; cin >> N;
  // @InpVec(N, A) [5R8G20iN]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [5R8G20iN]

  ll K = 0;
  REP(i, 0, N) K = max(K, (ll)bit_width((u64)A[i]));

  auto root = new Trie<2, '0', pll>();

  REP(i, 0, N) {
    string s = du2.to_string(A[i]);
    ranges::reverse(s);
    if (ssize(s) < K) s += string(K - ssize(s), '0');
    auto p = root->insert(s);
    while (true) {
      p->user.first++;
      p->user.second += A[i];
      if (p == root) break;
      p = p->parent;
    }
  }
  DLOGK(root->show());

  ll ans = 0;
  REP(i, 0, N) {
    string s = du2.to_string(A[i]);
    ranges::reverse(s);
    if (ssize(s) < K) s += string(K - ssize(s), '0');
    ll cur = 0;
    bool az = true;
    auto p = root;
    ll pat = 0;
    REP(k, 0, ssize(s)) {
      if (not p) break;
      auto pn = p->get_child_offset(s[k] - '0');
      auto pr = p->get_child_offset(1 - (s[k] - '0'));
      if (az) {
        if (pr) {
          DLOGKL("  ", i, k, pr->user.second, pr->user.first);
          cur += (pr->user.second + A[i] * pr->user.first) >> k;
        }
        if (k == ssize(s) - 1) {
          if (pn) cur += pn->user.first;
        }else {
          az = s[k] == '0';
          p = pn;
          pat += ((s[k] - '0') << k);
        }
      }else {
        if (pn) {
          DLOGKL("  ", i, k, pat, pn->user.second, pn->user.first);
          cur += (((pn->user.second - pat * pn->user.first) >> k) + ((A[i] >> k) * pn->user.first)) + pn->user.first;
        }
        if (k == ssize(s) - 1) {
          if (pr) cur += pr->user.first;
        }else {
          az = false;
          p = pr;
          pat += ((1 - (s[k] - '0')) << k);
        }
      }
      DLOGK(i, k, cur);
    }
    /*
    if (p) {
      cur += ((p->user.second - pat * p->user.first) >> ssize(s)) + p->user.first;
    }
    DLOGK(i, cur);
    */
    ans += cur;
  }
  DLOGKL("raw", ans);
  ll diag = 0;
  REP(i, 0, N) {
    ll k = countr_zero((u64)A[i]);
    diag += (A[i] >> k);
  }
  DLOGK(diag);
  ans = diag + (ans - diag) / 2;
  cout << ans << endl;

  return 0;
}

