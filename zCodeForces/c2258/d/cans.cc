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

// @@ !! LIM(forall debug cmpNaive)

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

// ---- inserted library file cmpNaive.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/cmpNaive.cc

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
  auto solve = [&]() -> void {
    ll N, M; cin >> N >> M;
    // @InpMVec(N, ((L1, dec=1), (R1, dec=0))) [A5HW6caf]
    auto L1 = vector(N, ll());
    auto R1 = vector(N, ll());
    for (int i = 0; i < N; i++) {
      ll v1; cin >> v1; v1 -= 1; L1[i] = v1;
      ll v2; cin >> v2; v2 -= 0; R1[i] = v2;
    }
    // @End [A5HW6caf]
    // @InpMVec(M, ((L2, dec=1), (R2, dec=0))) [CLkysrKD]
    auto L2 = vector(M, ll());
    auto R2 = vector(M, ll());
    for (int i = 0; i < M; i++) {
      ll v1; cin >> v1; v1 -= 1; L2[i] = v1;
      ll v2; cin >> v2; v2 -= 0; R2[i] = v2;
    }
    // @End [CLkysrKD]
    ll END1 = 1;
    ll END2 = 2;
    ll START1 = 3;
    ll START2 = 4;
    vector<pll> ev;
    REP(i, 0, N) {
      ev.emplace_back(L1[i], START1);
      ev.emplace_back(R1[i], END1);
    }
    REP(i, 0, M) {
      ev.emplace_back(L2[i], START2);
      ev.emplace_back(R2[i], END2);
    }
    ranges::sort(ev);

    ll cnt = 0;
    {
      bool b1 = false, b2 = false;
      for (auto [t, kd] : ev) {
        if (kd == END1) b1 = false;
        else if (kd == END2) b2 = false;
        else if (kd == START1) {
          if (b2) cnt++;
          b1 = true;
        }else if (kd == START2) {
          if (b1) cnt++;
          b2 = true;
        }
      }
    }
    auto better = [&](const vector<ll>& p, const vector<ll>& q) -> bool {
      REP(i, 0, ssize(p)) {
        if (p[i] > q[i]) return true;
        if (p[i] < q[i]) return false;
      }
      return false;
    };
    vector<ll> ans;
    REP(x, 0, 1LL << cnt) {
      vector<ll> res;
      ll seq = 0;
      ll run = 0;
      ll start = -1;
      bool b1 = false, b2 = false;
      for (auto [t, kd] : ev) {
        if (kd == END1) {
          if (run == 1) {
            if (t > start) res.push_back(t - start);
            if (b2) {
              run = 2;
              start = t;
            }else run = 0;
          }
          b1 = false;
        }else if (kd == END2) {
          if (run == 2) {
            if (t > start) res.push_back(t - start);
            if (b1) {
              run = 1;
              start = t;
            }else run = 0;
          }
          b2 = false;
        }else if (kd == START1) {
          if (b2) {
            assert(run == 2);
            if (x >> seq & 1) {
              if (t > start) res.push_back(t - start);
              run = 1;
              start = t;
            }
            seq++;
          }else {
            run = 1;
            start = t;
          }
          b1 = true;
        }else if (kd == START2) {
          if (b1) {
            assert(run == 1);
            if (x >> seq & 1) {
              if (t > start) res.push_back(t - start);
              run = 2;
              start = t;
            }
            seq++;
          }else {
            run = 2;
            start = t;
          }
          b2 = true;
        }else assert(0);
      }
      ranges::sort(res, greater<ll>());
      if (ans.empty()) ans = move(res);
      else if (better(res, ans)) ans = move(res);
    }
    cout << ssize(ans) << "\n";
    REPOUT(i, 0, ssize(ans), ans[i], " ");
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();
  return 0;
}
int body(istream& cin, ostream& cout) {
  auto solve = [&]() -> void {
    ll N, M; cin >> N >> M;
    // @InpMVec(N, ((L1, dec=1), (R1, dec=0))) [A5HW6caf]
    auto L1 = vector(N, ll());
    auto R1 = vector(N, ll());
    for (int i = 0; i < N; i++) {
      ll v1; cin >> v1; v1 -= 1; L1[i] = v1;
      ll v2; cin >> v2; v2 -= 0; R1[i] = v2;
    }
    // @End [A5HW6caf]
    // @InpMVec(M, ((L2, dec=1), (R2, dec=0))) [CLkysrKD]
    auto L2 = vector(M, ll());
    auto R2 = vector(M, ll());
    for (int i = 0; i < M; i++) {
      ll v1; cin >> v1; v1 -= 1; L2[i] = v1;
      ll v2; cin >> v2; v2 -= 0; R2[i] = v2;
    }
    // @End [CLkysrKD]

    ll END1 = 1;
    ll END2 = 2;
    ll START1 = 3;
    ll START2 = 4;
    vector<pll> ev;
    REP(i, 0, N) {
      ev.emplace_back(L1[i], START1);
      ev.emplace_back(R1[i], END1);
    }
    REP(i, 0, M) {
      ev.emplace_back(L2[i], START2);
      ev.emplace_back(R2[i], END2);
    }
    ranges::sort(ev);
    vector<ll> ans;

    using sta = pair<vector<ll>, ll>;
    auto betterFin = [&](vector<ll>& vs1, vector<ll>& vs2) {
      REP(i, 0, ssize(vs1)) {
        assert(i < ssize(vs2));
        if (vs1[i] > vs2[i]) return true;
        else if (vs1[i] < vs2[i]) return false;
      }
      return false;
    };
    auto func_start = [&](auto& runA, auto& runB, ll t) -> void {
      assert(runA.empty());
      if (runB.empty()) {
        runA.emplace_back(vector<ll>{}, t);
      }else {
        for (const auto& [vs, tt] : runB) {
          auto w = vs;
          if (t > tt) w.push_back(t - tt);
          ranges::sort(w, greater<ll>());
          DLOGKL("trying...", t, w, runA);
          auto tmp = move(runA);
          bool comparing = true;
          runA = vector<sta>();
          for (auto& p : tmp) {
            if (not comparing) {
              DLOG("     a");
              runA.push_back(move(p));
            }else if (p.first == w or betterFin(p.first, w)) {
              DLOG("     b");
              comparing = false;
              runA.push_back(move(p));
            }else if (betterFin(w, p.first)) {
              DLOG("     c");
              ;
            }else {
              DLOG("     d");
              runA.push_back(move(p));
            }
          }
          if (comparing) runA.emplace_back(w, t);
          DLOGKL("resulted...", runA);
        }
      }
    };
    auto func_end = [&](auto& runA, auto& runB, ll t) -> void {
      auto better = [&](sta& p, sta& q) -> bool {
        auto& [vp, tp] = p;
        auto& [vq, tq] = q;
        if (t - tq > t - tp) return false;
        else if (t - tq == t - tp) return betterFin(vp, vq);
        else if (t - tq < t - tp) {
          if (vq.empty() or t - tp > vq[0]) return true;
          return betterFin(vp, vq);
        }else assert(0);
      };
      bool bothStop = runB.empty();
      vector<ll> pFin{};
      for (auto& [vs, tt] : runA) {
        if (t > tt) vs.push_back(t - tt);
        ranges::sort(vs, greater<ll>());
        sta p(move(vs), t);
        if (not bothStop) {
          auto tmpB = move(runB);
          runB = vector<sta>();
          bool comparing = true;
          for (auto& q : tmpB) {
            if (not comparing) runB.push_back(move(q));
            else if (better(q, p) or q == p) {
              comparing = false;
              runB.push_back(move(q));
            }else if (better(p, q)) ;
            else runB.push_back(move(q));
          }
          if (comparing) runB.push_back(p);
        }else if (pFin.empty()) pFin = move(p.first);
        else if (betterFin(p.first, pFin)) pFin = move(p.first);
      }
      runA.resize(0);
      if (bothStop) {
        for (ll v : pFin) ans.push_back(v);
      }else {
        ll j0 = 0;
        for (; FORALL(i, 0, ssize(runB), j0 < ssize(runB[i].first) and runB[i].first[j0] == runB[0].first[j0]); j0++);
        if (j0 > 0) {
          REP(j, 0, j0) ans.push_back(runB[0].first[j]);
          for (auto& [vs, tt] : runB) vs.erase(vs.begin(), vs.begin() + j0);
        }
      }
    };

    vector<sta> run1, run2;
    for (auto [t, kd] : ev) {
      if (kd == START1) func_start(run1, run2, t);
      else if (kd == START2) func_start(run2, run1, t);
      else if (kd == END1) func_end(run1, run2, t);
      else if (kd == END2) func_end(run2, run1, t);
      else assert(0);
      DLOGK(t, kd);
      DLOGK(run1);
      DLOGK(run2);
#if 0
      assert(ssize(run1) <= 2);
      assert(ssize(run2) <= 2);
      if (run2.empty()) for (auto& [vs, tt] : run1) assert(ssize(vs) <= 2);
      if (run1.empty()) for (auto& [vs, tt] : run2) assert(ssize(vs) <= 2);
#endif
    }
    ranges::sort(ans, greater<ll>());
    cout << ssize(ans) << "\n";
    REPOUT(i, 0, ssize(ans), ans[i], " ");
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

