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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(debug updMaxMin intDiv forall binsearch trie sortedIndex)

// ---- inserted library file streamOut.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/streamOut.cc

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

string g_show_impl(unsigned __int128 x) {
  if (x == 0) return "0";
  string s;
  while (x > 0) {
    int d = (int)(x % 10);
    s.push_back((char)('0' + d));
    x /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}

string g_show_impl(__int128 x) {
  unsigned __int128 ux = (unsigned __int128)x;
  return x >= 0 ? g_show_impl(ux) : "-" + g_show_impl(~ux + 1);
}

// Both g_show_impl and operator<< are needed because of the implicit casting from __int128 to int etc.
ostream& operator<<(ostream& ostr, unsigned __int128 x) { return ostr << g_show(x); }
ostream& operator<<(ostream& ostr,          __int128 x) { return ostr << g_show(x); }


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

// ---- end streamOut.cc

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

// ---- inserted library file updMaxMin.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/updMaxMin.cc

template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}

// ---- end updMaxMin.cc

// ---- inserted library file intDiv.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/intDiv.cc

// imod, divFloor, divCeil

// imod(x, y) : remainder of x for y
// for y > 0:
//   imod(x, y)  = r where x = dy + r, 0 <= r < y
//   imod(x, -y) = r where x = dy + r, 0 >= r > y
// Thus, imod( 10,  7) =  3
//       imod(-10,  7) =  4
//       imod( 10, -7) = -4
//       imod(-10, -7) = -3
ll imod(ll x, ll y) {
  ll v = x % y;
  if ((x >= 0) == (y >= 0)) return v;
  else                      return v == 0 ? 0 : v + y;
}

// Integer Division; regardless pos/neg
ll divFloor(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return x / y;
    else       return (x - y - 1) / y;
  }else {
    if (y > 0) return (x - y + 1) / y;
    else       return x / y;
  }
}

ll divCeil(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return (x + y - 1) / y;
    else       return x / y;
  }else {
    if (y > 0) return x / y;
    else       return (x + y + 1) / y;
  }
}
//   Just a note.  For d \in Z and t \in R,
//       d < t <=> d < ceil(t),     d <= t <=> d <= floor(t),
//       d > t <=> d > floor(t),    d >= t <=> d >= ceil(t).

// ---- end intDiv.cc

// ---- inserted library file forall.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/forall.cc

#define EX_REP_LL(i, from, to) for (ll i = (from); i < (to); i++)
#define EX_REP_RB(x, coll) for (auto x : coll)
#define EXGEN(rep_part, cond, yes, no_behaviour) ([&]() { rep_part if (cond) return (yes); no_behaviour; }())
#define EXISTS_BASE(rep_part, cond) EXGEN(rep_part, cond, true, return false)
#define EXFIND_BASE(rep_part, cond, t) EXGEN(rep_part, cond, t, assert(0))
#define EXFIND_D_BASE(rep_part, cond, t, def) EXGEN(rep_part, cond, t, return def)

#define EXISTS(i, from, to, cond) EXISTS_BASE(EX_REP_LL(i, from, to), cond)
#define FORALL(i, from, to, cond) (not EXISTS(i, from, to, not (cond)))
#define EXFIND(i, from, to, cond) EXFIND_BASE(EX_REP_LL(i, from, to), cond, i)
#define EXFIND_D(i, from, to, cond, def) EXFIND_D_BASE(EX_REP_LL(i, from, to), cond, i, def)

#define EXISTS_C(x, coll, cond) EXISTS_BASE(EX_REP_RB(x, coll), cond)
#define FORALL_C(x, coll, cond) (not EXISTS_C(x, coll, not (cond)))
#define EXFIND_C(x, coll, cond) EXFIND_BASE(EX_REP_RB(x, coll), cond, x)
#define EXFIND_D_C(x, coll, cond, def) EXFIND_D_BASE(EX_REP_RB(x, coll), cond, x, def)

#define COUNT_BASE(rep_part, cond) ([&](){ ll ret = 0; rep_part if (cond) ret++; return ret; }())
#define COUNT(i, from, to, cond) COUNT_BASE(EX_REP_LL(i, from, to), cond)
#define COUNT_C(x, coll, cond) COUNT_BASE(EX_REP_RB(x, coll), cond)

#define IMPLIES(a, b) (not (a) or (b))

// ---- end forall.cc

// ---- inserted library file binsearch.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/binsearch.cc

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
  ll rep = rep_in_t > (T)lim ? lim : llround(rep_in_t) + 1;
  for (ll r = 0; r < rep; r++) {
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

// ---- inserted library file trie.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/trie.cc

constexpr int TRIE_SET_MULTI = 0;
constexpr int TRIE_SET_SINGLE = 1;
constexpr int TRIE_SET_NONE = 2;

template <int bt_size, char from, int set_mode = TRIE_SET_MULTI, typename User = monostate,
          typename S = string, bool compact = (8 <= bt_size and bt_size <= 63), bool has_offset = true>
struct Trie {

  template <typename RetType>
  static consteval RetType make_default_intval(int x) {
    if constexpr (is_same_v<RetType, int>) return x;
    else return {};
  }

  Trie* parent = nullptr;

  using c_pat_t = conditional_t<compact, unsigned long long, monostate>;
  [[no_unique_address]] c_pat_t c_pat{};

  using cpt_children_t = conditional_t<compact, vector<Trie*>, monostate>;
  [[no_unique_address]] cpt_children_t cpt_children{};

  using children_t = conditional_t<compact, monostate, array<Trie*, bt_size>>;
  [[no_unique_address]] children_t children{};

  using offset_t = conditional_t<has_offset, int, monostate>;
  [[no_unique_address]] offset_t offset = make_default_intval<offset_t>(-1);

  using reside_t = conditional_t<set_mode == TRIE_SET_NONE, monostate, int>;
  [[no_unique_address]] reside_t reside = make_default_intval<reside_t>(0);

  using size_st_t = conditional_t<set_mode == TRIE_SET_NONE, monostate, int>;
  [[no_unique_address]] size_st_t size_st = make_default_intval<size_st_t>(0);

  [[no_unique_address]] User user{};

  /*
    Note on the default value of compact: When `compact' = true, the size of Trie increases 4 bytes per bt_size,
    as the type of `children' is array<Trie*, bt_size>.  When `compact' = false, the size of Trie itself
    does not depend on the value of bt_size, but the memory consumption increases when a string is added,
    as the type of `cpt_children` is vector<Trie*>.  The size of Trie with (compact=true, bt_size=4) is
    the same as that with (compact=False).  (Warning: if you use -D_GLIBCXX_DEBUG, the results may be
    different.)  Thus, when bt_size <= 4, `comapct' should definitely be false.
  */

  Trie() = default;
  Trie(Trie* p, int offset_) : parent(p) {
    if constexpr (has_offset) offset = offset_;
  }

  Trie* get_child_offset(int d) const {
    if constexpr(compact) {
      static_assert(bt_size <= 63);
      ll idx = popcount(c_pat & ((1ULL << d) - 1));
      return (c_pat >> d & 1) ? cpt_children[idx] : nullptr;
    }else {
      Trie* p = children[d];
      return p ? p : nullptr;
    }
  }
  Trie* get_child_val(int c) const { return get_child_offset(c - from); }

  Trie* get_or_create_child_offset(int d) {
    if (Trie* p0 = get_child_offset(d); p0) return p0;
    Trie* p = new Trie(this, d);
    if constexpr(compact) {
      ll idx = popcount(c_pat & ((1ULL << d) - 1));
      cpt_children.insert(cpt_children.begin() + idx, p);
      c_pat |= 1ULL << d;
    }else {
      children[d] = p;
    }
    return p;
  }
  Trie* get_or_create_child_val(int c) { return get_or_create_child_offset(c - from); }

  /*
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
  */

  Trie* get_or_create_node(const auto& s) {
    Trie* tr = this;
    for (auto c : s) tr = tr->get_or_create_child_val(c);
    return tr;
  }
  Trie* get_or_create_node(const char* s) { return get_or_create_node(string_view(s)); }

  Trie* get_node(const auto& s) const {
    Trie* tr = const_cast<Trie*>(this);
    for (auto c : s) {
      tr = tr->get_child_val(c);
      if (not tr) return nullptr;
    }
    return tr;
  }
  Trie* get_node(const char* s) const { return get_node(string_view(s)); }

  Trie* search(const auto& s) const {
    Trie* p = get_node(s);
    if (p and p->reside == 0) p = nullptr;
    return p;
  }
  Trie* search(const char* s) const { return search(string_view(s)); }

  Trie* insert(const auto& s) {
    Trie* tr = get_or_create_node(s);
    if constexpr (set_mode == TRIE_SET_SINGLE) {
      if (tr->reside == 0) {
        tr->reside = 1;
        for (Trie* p = tr; p; p = p->parent) p->size_st++;
      }
    }else if constexpr (set_mode == TRIE_SET_MULTI) {
      tr->reside++;
      for (Trie* p = tr; p; p = p->parent) p->size_st++;
    }
    return tr;
  }
  Trie* insert(const char* s) { return insert(string_view(s)); }

  void erase() {
    if constexpr (set_mode == TRIE_SET_SINGLE or set_mode == TRIE_SET_MULTI) {
      if (reside > 0) {
        for (Trie* tr = this; tr; tr = tr->parent) tr->size_st--;
        reside--;
      }
    }
  }
  void erase(const auto& s) {
    Trie* p = search(s);
    if (p) p->erase();
  }
  void erase(const char* s) { erase(string_view(s)); }

  int get_offset() const {
    if constexpr (has_offset) return offset;
    else {
      Trie* p = parent;
      if (not p) return -1;
      for (int d = 0; d < bt_size; d++) if (p->get_child_offset(d) == this) return d;
      assert(0);
    }
  }

  S repr() const {
    S ret;
    for (const Trie* tr = this; true; tr = tr->parent) {
      ll d = tr->get_offset();
      if (d < 0) break;
      ret.push_back((char)(from + tr->get_offset()));
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }

  void _elem_list_sub(auto& vec) const {
    for (int i = 0; i < reside; i++) vec.push_back(repr());
    for (int i = 0; i < bt_size; i++) if (Trie* p = get_child_offset(i); p) p->_elem_list_sub(vec);
  }

  vector<S> elem_list() const {
    vector<S> ret;
    _elem_list_sub(ret);
    return ret;
  }

  using show_elem_tp = conditional_t<is_same_v<User, monostate>, tuple<S, int, int>, tuple<S, int, int, int, User>>;
  using show_tp = vector<show_elem_tp>;

  void _show_sub_add(string& s) const {
    s += "(" + repr() + ", " + to_string(reside) + ", " + to_string(size_st);
    if constexpr (not (is_same_v<User, monostate>)) s += ", " + g_show(user);
    s += "),\n  ";
  }

  void _show_sub(string& s, bool elemonly) const {
    auto add = [&]() -> void {
      s += "(" + repr();
      if constexpr (set_mode == TRIE_SET_SINGLE or set_mode == TRIE_SET_MULTI) {
        s += ", " + to_string(reside) + ", " + to_string(size_st);
      }
      if constexpr (not (is_same_v<User, monostate>)) s += ", " + g_show(user);
      s += "),\n  ";
    };

    if constexpr (set_mode == TRIE_SET_SINGLE or set_mode == TRIE_SET_MULTI) {
      if (reside > 0 or not elemonly) add();
    }else add();
    for (int i = 0; i < bt_size; i++) if (Trie* p = get_child_offset(i); p) p->_show_sub(s, elemonly);
  }

  string show(bool elemonly = true) const {
    string ret = "[ ";
    _show_sub(ret, elemonly);
    ret.pop_back(); ret.pop_back(); ret.pop_back(); ret.pop_back();
    ret += "]";
    return ret;
  }


};


// ---- end trie.cc

// ---- inserted library file sortedIndex.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/sortedIndex.cc

template<typename INT = long long int>
vector<INT> sortedIndexCFAI(const auto& vec, auto idx_comp) { // Comparison Function Arguments are Indices
  vector<INT> ret(vec.size());
  iota(ret.begin(), ret.end(), (INT)0);
  sort(ret.begin(), ret.end(), idx_comp);
  return ret;
}

template<typename INT = long long int, typename Collection, typename Comp = less<typename Collection::value_type>>
vector<INT> sortedIndex(const Collection& vec, Comp comp = Comp()) {
  return sortedIndexCFAI<INT>(vec, [&vec, &comp](INT i, INT j) { return comp(vec[i], vec[j]); });
}

template<typename INT = long long int>
pair<vector<INT>, vector<INT>> sortedIndex2CFAI(const auto& vec, auto idx_comp) {
  auto ord2idx = sortedIndexCFAI<INT>(vec, idx_comp);
  vector<INT> idx2ord(vec.size());
  for (size_t i = 0; i < vec.size(); i++) idx2ord[ord2idx[i]] = (INT)i;
  return {move(ord2idx), move(idx2ord)};
}

template<typename INT = long long int>
pair<vector<INT>, vector<INT>> sortedIndex2(const auto& vec, auto comp) {
  return sortedIndex2CFAI<INT>(vec, [&vec, &comp](INT i, INT j) { return comp(vec[i], vec[j]); });
}

template<typename INT = long long int, typename Collection>
pair<vector<INT>, vector<INT>> sortedIndex2(const Collection& vec) {
  return sortedIndex2<INT>(vec, less<typename Collection::value_type>());
}


// ---- end sortedIndex.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, S, type=string) [ryYFLnSt]
  // This part (until atmark + "End") was generated by a script written by myself.
  // Source: https://github.com/yamate11/compprog-clib/blob/master/tool/inputExpand
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [ryYFLnSt]

  auto o2i = sortedIndex(S, [&](const string& s, const string& t) -> bool { return ssize(s) < ssize(t); });
  
  using MyTrie = Trie<26, 'a', TRIE_SET_MULTI>;
  MyTrie* root = new MyTrie;
  
  ll ans = 0;
  REP(o, 0, N) {
    ll i = o2i[o];
    DLOGK(i, S[i]);
    ll sz = ssize(S[i]);
    REP(len, 1, sz) {
      DLOGKL("  ", len);
      MyTrie* p = root;
      REP(j, 0, len) {
        char c = S[i][sz - len + j];
        p = p->get_child_val(c);
        if (not p) break;
        ans += p->reside;
        DLOGKL("    ", c, ans);
      }
    }
    {
      MyTrie* p = root;
      DLOGKL("  ", sz);
      REP(j, 0, sz) {
        char c = S[i][j];
        p = p->get_or_create_child_val(c);
        ans += p->reside;
        DLOGKL("    ", c, ans);
      }
      p->reside++;
    }
  }
  cout << ans << "\n";
  
  return 0;
}

