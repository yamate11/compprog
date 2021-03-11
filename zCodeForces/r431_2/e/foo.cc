#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug)
// --> f:<< debug
// ---- inserted function << from util.cc
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

// ---- end <<
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

#define DUP1(E1)       #E1 "=", E1
#define DUP2(E1,E2)    DUP1(E1), DUP1(E2)
#define DUP3(E1,...)   DUP1(E1), DUP2(__VA_ARGS__)
#define DUP4(E1,...)   DUP1(E1), DUP3(__VA_ARGS__)
#define DUP5(E1,...)   DUP1(E1), DUP4(__VA_ARGS__)
#define DUP6(E1,...)   DUP1(E1), DUP5(__VA_ARGS__)
#define DUP7(E1,...)   DUP1(E1), DUP6(__VA_ARGS__)
#define DUP8(E1,...)   DUP1(E1), DUP7(__VA_ARGS__)
#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME
#define DUP(...)          GET_MACRO(__VA_ARGS__, DUP8, DUP7, DUP6, DUP5, DUP4, DUP3, DUP2, DUP1)(__VA_ARGS__)
#define DLOGK(...)        DLOG(DUP(__VA_ARGS__))
#define DLOGKL(lab, ...)  DLOG(lab, DUP(__VA_ARGS__))

// ---- end debug.cc
// @@ !! LIM  -- end mark --

/*
struct StDatOp {
  using dat_t = int;
  using op_t = int;
  static const dat_t unit_dat = 0;
  static const op_t unit_op = 0;
  static dat_t add(dat_t x, dat_t y) { return unit_dat; }
  static dat_t appl(op_t f, dat_t x) { return unit_dat; }
};
*/

template <typename T>
struct STNode {
  using dat_lt = typename T::dat_t;
  using op_lt = typename T::op_t;
  STNode* lo;
  STNode* hi;
  dat_lt val;
  STNode() : lo(0), hi(0), val(T::unit_dat) {}

  void upd_sub(int p, op_lt f, int l, int r) {
    if (r == l + 1) {
      assert(l == p);
      val = T::appl(f, val)
      // DLOGKL("one set", val, l, r);
      return;
    }
    int m = (l + r) / 2;
    if (p < m) {
      if (!lo) lo = new STNode();
      lo->upd_sub(p, f, l, m);
    }else {
      if (!hi) hi = new STNode();
      hi->upd_sub(p, f, m, r);
    }
    dat_lt x = lo ? lo->val : T::unit_dat;
    dat_lt y = hi ? hi->val : T::unit_dat;
    val = T::add(x, y);
    // DLOGKL("long set", val, l, r);
  }

  dat_lt qry_sub(int l_ran, int r_ran, int l, int r) {
    // DLOGKL("in qry_sub", l_ran, r_ran, l, r);
    dat_lt ret = T::unit_dat;
    if (l_ran <= l && r <= r_ran) {
      // DLOG("** 1");
      ret = val;
    }else if (r_ran <= l || r <= l_ran) {
      // DLOG("** 2");
      ret = T::unit_dat;
    }else {
      int m = (l + r) / 2;
      dat_lt x = lo ? lo->qry_sub(l_ran, r_ran, l, m) : T::unit_dat;
      dat_lt y = hi ? hi->qry_sub(l_ran, r_ran, m, r) : T::unit_dat;
      ret = T::add(x, y);
    }
    // DLOGKL("query", ret, l, r);
    return ret;
  }

};

template <typename T>
struct DynSegTree {
  STNode<T>* top;
  int start;
  int end;

  DynSegTree(int start_, int end_) : start(start_), end(end_) {
    top = new STNode<T>();
  }
    
  void update(int p, typename T::op_t f) {
    assert(start <= p && p < end);
    top->upd_sub(p, f, start, end);
  }

  typename T::dat_t query(int l_ran, int r_ran) {
    assert(start <= l_ran && l_ran <= r_ran && r_ran <= end);
    if (l_ran == r_ran) return T::unit_dat;
    return top->qry_sub(l_ran, r_ran, start, end);
  }

};

template <typename T>
struct ST2Node {
  using dat_lt = typename T::dat_t;
  using op_lt = typename T::op_t;
  ST2Node* lo;
  ST2Node* hi;
  DynSegTree<T> st;
  STNode(int a, int b) : lo(0), hi(0), st(a, b) {}

  void upd_sub(int p, op_lt f, op_lt f2, int l, int r) {
    if (r == l + 1) {
      assert(l == p);
      val = T::appl(f, val)
      return;
    }
    int m = (l + r) / 2;
    if (p < m) {
      if (!lo) lo = new STNode();
      lo->upd_sub(p, f, l, m);
    }else {
      if (!hi) hi = new STNode();
      hi->upd_sub(p, f, m, r);
    }
    dat_lt x = lo ? lo->val : T::unit_dat;
    dat_lt y = hi ? hi->val : T::unit_dat;
    val = T::add(x, y);
  }

  dat_lt qry_sub(int l_ran, int r_ran, int l, int r) {
    dat_lt ret = T::unit_dat;
    if (l_ran <= l && r <= r_ran) {
      ret = val;
    }else if (r_ran <= l || r <= l_ran) {
      ret = T::unit_dat;
    }else {
      int m = (l + r) / 2;
      dat_lt x = lo ? lo->qry_sub(l_ran, r_ran, l, m) : T::unit_dat;
      dat_lt y = hi ? hi->qry_sub(l_ran, r_ran, m, r) : T::unit_dat;
      ret = T::add(x, y);
    }
    return ret;
  }

};

template <typename T>
struct DynSegTree {
  STNode<T>* top;
  int start;
  int end;

  DynSegTree(int start_, int end_) : start(start_), end(end_) {
    top = new STNode<T>();
  }
    
  void update(int p, typename T::op_t f) {
    assert(start <= p && p < end);
    top->upd_sub(p, f, start, end);
  }

  typename T::dat_t query(int l_ran, int r_ran) {
    assert(start <= l_ran && l_ran <= r_ran && r_ran <= end);
    if (l_ran == r_ran) return T::unit_dat;
    return top->qry_sub(l_ran, r_ran, start, end);
  }

};


struct MinSubst {
  using store_t = ll;
  using dat_t = ll;
  using op_t = optional<ll>;
  static void store_put(store_t& store, dat_t v) { store = v; };
  static dat_t store_get(const store_t& store) { return store; };
  static dat_t add(dat_t x, dat_t y) { return min(x, y); }
  static dat_t appl(op_t f, dat_t x) { return f.value_or(x); }
  static const dat_t unit_dat = LLONG_MAX;
  static const op_t unit_op;
};
const MinSubst::op_t MinSubst::unit_op = nullopt;

struct SumSubst {
  using store_t = ll;
  using dat_t = ll;
  using op_t = optional<ll>;
  static void store_put(store_t& store, dat_t v) { store = v; };
  static dat_t store_get(const store_t& store) { return store; };
  static dat_t add(dat_t x, dat_t y) { return x + y; }
  static dat_t appl(op_t f, dat_t x) { return f.value_or(x); }
  static const dat_t unit_dat = 0;
  static const op_t unit_op;
};
const SumSubst::op_t SumSubst::unit_op = nullopt;


int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    DynSegTree<MinSubst> st(0, 10);
    st.update(3, 5);
    assert(st.query(3, 4) == 5);
    st.update(5, 2);
    assert(st.query(0, 3) == LLONG_MAX);
    assert(st.query(0, 4) == 5);
    assert(st.query(0, 10) == 2);
    assert(st.query(5, 10) == 2);
    st.update(5, 10);
    assert(st.query(0, 10) == 5);
  }
  {
    DynSegTree<SumSubst> st(0, 10);
    st.update(3, 5);
    assert(st.query(3, 4) == 5);
    st.update(5, 2);
    assert(st.query(0, 3) == 0);
    assert(st.query(0, 4) == 5);
    assert(st.query(0, 10) == 7);
    assert(st.query(5, 10) == 2);
    st.update(5, 10);
    assert(st.query(0, 10) == 15);
  }


  return 0;
}

