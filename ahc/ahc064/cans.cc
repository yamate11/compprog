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

// @@ !! LIM(random debug forall)

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

  double rand(double a, double b) {
    if (!(a <= b)) {
      throw std::runtime_error("Random.rand: invalid range");
    }
    std::uniform_real_distribution<double> dist(a, b);
    return dist(rng);
  }

  pair<ll, ll> select2(ll i, ll j) {
    if (j - i < 2) {
      throw std::runtime_error("Random.select2: range too small");
    }
    ll x = range(i, j);
    ll y = range(i, j - 1);
    if (y >= x) ++y;
    if (x > y) swap(x, y);
    return {x, y};
  }

  template<typename RandomIt>
  void shuffle(RandomIt first, RandomIt last) { std::shuffle(first, last, rng); }

};

random_device Random::the_random_device;

// ---- end random.cc

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
// https://github.com/yamate11/compprog-clib/blob/master/debug.cc

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

// ---- inserted library file forall.cc

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

// @@ !! LIM -- end mark --

ll R; 

struct pos_t {
  ll row;
  ll part;  // upper = 0, lower = 1
  ll col;
  string fmt() const { return format("{} {} {}", row, part, col); }
  friend ostream& operator<<(ostream& ostr, const pos_t& p) { return ostr << format("[{}]", p.fmt()); }
  bool operator<=>(const pos_t&) const = default;
};

struct strans_t {
  ll type;
  ll upper;
  ll lower;
  ll num;
  string fmt() const { return format("{} {} {} {}", type, upper, lower, num); }
  friend ostream& operator<<(ostream& ostr, const strans_t& tr) { return ostr << format("[{}]", tr.fmt()); }
  bool operator<=>(const strans_t&) const = default;
};

using move_t = vector<strans_t>;

struct state_t {
  vector<vector<vector<ll>>> dat;
  friend ostream& operator<<(ostream& ostr, const state_t& st) { return ostr << st.dat; }
  ll evaluate() {
    ll val = 0;
    REP(r, 0, R) {
      const auto& vupper = dat[r][0];
      const auto& vlower = dat[r][1];
      if (not vupper.empty() and vupper[0] == r * 10) val += 1000;
      if (not vlower.empty() and vlower[0] == r * 10 + 9) val += 1000;
      REP(i, 0, ssize(vupper) - 1) {
        if (vupper[i] + 1 == vupper[i + 1] and vupper[i + 1] % 10 != 0) val += 100;
      }
      REP(i, 0, ssize(vlower) - 1) {
        if (vlower[i] - 1 == vlower[i + 1] and vlower[i] % 10 != 0) val += 100;
      }
    }
    return val;
  }
};

void printans(const auto& ans) {
  cout << ssize(ans) << "\n";
  for (const auto& vec : ans) {
    cout << ssize(vec) << "\n";
    for (const auto& tr : vec) { cout << tr.fmt() << "\n"; }
  }
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);


  cin >> R;

  Random rand;

  const int max_turn = 500;
  const int sch_width = 50;
  const int sch_depth = 3;

  vector Y(R, vector(2, vector(0, 0LL)));
  REP(i, 0, R) REP(j, 0, 10) {
    ll a; cin >> a;
    Y[i][0].push_back(a);
  }
  vector<move_t> ans;

  /*
  auto is_end_state = [&](const state_t& st) -> bool {
    REP(r, 0, R) {
      if (not (ssize(st.dat[r][0]) == 10 and st.dat[r][1].empty())) return false;
      REP(i, 0, 10) if (st.dat[r][0][i] != r * 10 + i) return false;
    }
    return true;
  };
  */

  auto is_half_end_state = [&](const state_t& st) -> bool {
    REP(r, 0, R) {
      if (ssize(st.dat[r][0]) + ssize(st.dat[r][1]) != 10) return false;
      REP(i, 0, ssize(st.dat[r][0])) if (st.dat[r][0][i] != r * 10 + i) return false;
      REP(i, 0, ssize(st.dat[r][1])) if (st.dat[r][1][i] != r * 10 + 9 - i) return false;
    }
    return true;
  };

  auto cuttable = [&](const auto vec, ll type, ll r) -> vector<ll> {
    vector<ll> ret;
    if (vec.empty()) return ret;
    if (type == 0) {
      if (vec[0] != r * 10) ret.push_back(0);
      REP(i, 0, ssize(vec) - 1) {
        if (vec[i] + 1 != vec[i + 1] or vec[i + 1] % 10 == 0) ret.push_back(i + 1);
      }
    }else if (type == 1) {
      if (vec[0] != r * 10 + 9) ret.push_back(0);
      REP(i, 0, ssize(vec) - 1) {
        if (vec[i] - 1 != vec[i + 1] or vec[i] % 10 == 0) ret.push_back(i + 1);
      }
    }else assert(0);
    return ret;
  };

  auto get_moves = [&](const state_t& st) -> vector<move_t> {
    auto get_back = [&](ll rr, ll part) -> ll {
      if (st.dat[rr][part].empty()) return -1;
      return st.dat[rr][part].back();
    };

    auto add_one2 = [&](move_t& mv, ll iU, ll iL) -> void {
      ll sz0 = ssize(st.dat[iU][0]);
      ll sz1 = ssize(st.dat[iL][1]);
      auto vec0 = cuttable(st.dat[iU][0], 0, iU);
      auto vec1 = cuttable(st.dat[iL][1], 1, iL);
      vector<pll> ccands;
      for (ll p : vec0) if (sz0 - p + sz1 <= 20) ccands.emplace_back(0, sz0 - p);
      for (ll p : vec1) if (sz1 - p + sz0 <= 15) ccands.emplace_back(1, sz1 - p);
      if (ccands.empty()) return;
      ll i0 = rand.range(0, ssize(ccands));
      auto [type, len] = ccands[i0];
      mv.push_back(strans_t(type, iU, iL, len));
    };

    auto add_one = [&](move_t& mv, pll p) -> void { add_one2(mv, p.first, p.second); };
    
    auto conflict = [&](ll iU, ll iL, ll jU, ll jL) -> bool {
      if (iU < jU and iL < jL) return false;
      if (iU > jU and iL > jL) return false;
      return true;
    };

    auto extend_move = [&](move_t& mv) -> void {
      vector<ll> ivecU;
      vector<ll> ivecL;
      REP(j, 0, R) if (FORALL(k, 0, ssize(mv), mv[k].upper != j and mv[k].lower != j)) {
        ivecU.push_back(j);
        ivecL.push_back(j);
      }
      rand.shuffle(ALL(ivecU));
      rand.shuffle(ALL(ivecL));
      for (ll iU : ivecU) for (ll iL : ivecL) {
          if (FORALL(k, 0, ssize(mv), not conflict(mv[k].upper, mv[k].lower, iU, iL))
              and (not st.dat[iU][0].empty() or not st.dat[iL][1].empty())) {
            add_one2(mv, iU, iL);
          }
        }
    };
    
    vector<move_t> ret;
    vector<pll> pri;
    REP(r0, 0, R) REP(r1, 0, R) {
      ll b0 = get_back(r0, 0);
      ll b1 = get_back(r1, 1);
      if (b0 < 0 and b1 == r0 * 10) pri.emplace_back(r0, r1);
      if (b1 < 0 and b0 == r0 * 10 + 9) pri.emplace_back(r0, r1);
      if (b0 >= 0 and b1 >= 0 and b0 + 1 == b1 and b1 % 10 != 0) {
        auto check = [&]() -> bool {
          ll sz0 = ssize(st.dat[r0][0]);
          ll sz1 = ssize(st.dat[r1][1]);
          if (sz0 + sz1 <= 20) return true;
          auto vec0 = cuttable(st.dat[r0][0], 0, r0);
          auto vec1 = cuttable(st.dat[r1][1], 1, r1);
          if (not vec0.empty() and sz0 - vec0.back() + sz1 <= 20) return true;
          if (not vec1.empty() and sz1 - vec1.back() + sz0 <= 15) return true;
          return false;
        };
        if (check()) pri.emplace_back(r0, r1);
      }
    }
    ll sz = ssize(pri);
    if (sz > 0) {
      REP(i, 0, sz) {
        move_t mv;
        add_one(mv, pri[i]);
        vector<pll> tmp;
        REP(j, 0, sz) {
          if (j == i) continue;
          tmp.push_back(pri[i]);
        }
        rand.shuffle(ALL(tmp));
        for (const auto& [p, q] : tmp) {
          if (FORALL(k, 0, ssize(mv), not conflict(mv[k].upper, mv[k].lower, p, q))) add_one2(mv, p, q);
        }
        extend_move(mv);
        ret.push_back(move(mv));
      }
    }else {
      move_t mv;
      extend_move(mv);
      ret.push_back(move(mv));
    }
    return ret;
  };

  auto exec_move = [&](const move_t& mv, const state_t& st) -> state_t {
    state_t ret(st);
    for (const auto& tr : mv) {
      auto& src  = (tr.type == 0) ? ret.dat[tr.upper][0] : ret.dat[tr.lower][1];
      auto& dest = (tr.type == 0) ? ret.dat[tr.lower][1] : ret.dat[tr.upper][0];
      assert(ssize(src) >= tr.num);
      assert(ssize(dest) + tr.num <= (tr.type == 0 ? 20 : 15));
      REP(i, 0, tr.num) { dest.push_back(src.back()); src.pop_back(); }
    }
    return ret;
  };

  auto add_last_move = [&](auto& vec, const state_t& st) {
    move_t mv;
    REP(r, 0, R) {
      ll len = ssize(st.dat[r][1]);
      if (len > 0) mv.push_back(strans_t(1, r, r, len));
    }
    if (not mv.empty()) ans.push_back(move(mv));
  };

  state_t init_state(move(Y));

  using sta = tuple<ll, move_t, state_t>;
  vector<sta> cands_init;
  auto cands = cands_init;
  auto put_cands = [&](auto& vec, ll score, move_t mv, state_t st) -> void {
    vec.emplace_back(score, move(mv), move(st));
  };

  state_t cur_state(move(init_state));
  for (ll _turn = 0; _turn < max_turn; _turn++) {
    if (is_half_end_state(cur_state)) {
      add_last_move(cands, cur_state);
      break;
    }
    cands = cands_init;
    for (const move_t& mv : get_moves(cur_state)) {
      auto st = exec_move(mv, cur_state);
      ll score = st.evaluate();
      put_cands(cands, score, move(mv), move(st));
    }
    for (int _i = 1; _i < sch_depth; _i++) {
      auto prev = move(cands);
      cands = cands_init;
      for (auto& [sc, orig_mv, st] : prev) {
        for (const move_t& mv : get_moves(st)) {
          auto new_st = exec_move(mv, st);
          ll score = new_st.evaluate();
          put_cands(cands, score, orig_mv, move(new_st));
        }
      }
      ranges::sort(cands, [](sta elem1, sta elem2) { return get<0>(elem1) > get<0>(elem2); });
      if (ssize(cands) >= sch_width) cands.resize(sch_width);
    }
    auto& [sc, orig_mv, st] = cands[0];
    cur_state = exec_move(orig_mv, cur_state);
    ans.push_back(move(orig_mv));
    DLOGK(_turn, sc, cur_state.evaluate());
  }
  
  printans(ans);

  return 0;
}

