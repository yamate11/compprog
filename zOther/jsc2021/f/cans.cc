#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(f:<< debug)
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
#define DUP9(E1,...)   DUP1(E1), DUP8(__VA_ARGS__)
#define DUP10(E1,...)   DUP1(E1), DUP9(__VA_ARGS__)
#define DUP11(E1,...)   DUP1(E1), DUP10(__VA_ARGS__)
#define DUP12(E1,...)   DUP1(E1), DUP11(__VA_ARGS__)
#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,NAME,...) NAME
#define DUP(...)          GET_MACRO(__VA_ARGS__, DUP12, DUP11, DUP10, DUP9, DUP8, DUP7, DUP6, DUP5, DUP4, DUP3, DUP2, DUP1)(__VA_ARGS__)
#define DLOGK(...)        DLOG(DUP(__VA_ARGS__))
#define DLOGKL(lab, ...)  DLOG(lab, DUP(__VA_ARGS__))

// ---- end debug.cc
// @@ !! LIM  -- end mark --

template<typename DAT, typename OP> 
struct Node {
  // ll lo;
  // ll hi;
  DAT val;
  OP op;
  Node<DAT, OP> *lo_node;
  Node<DAT, OP> *hi_node;
  Node(/*ll lo_, ll hi_,*/ DAT val_, OP op_)
    : /*lo(lo_), hi(hi_),*/ val(val_), op(op_) {}

};

template<typename DAT, typename OP,
         typename Fadd, typename Fcomp, typename Fappl>
struct DynSegTree {
  /*int size;*/
  int tot_lo;
  int tot_hi;
  int height;
  Node<DAT, OP>* node;
  DAT unit_dat;
  OP unit_op;
  Fadd add;
  Fcomp comp;
  Fappl appl;

  DynSegTree(ll lo, ll hi, DAT unit_dat_, OP unit_op_,
             Fadd add_, Fcomp comp_, Fappl appl_)
    : tot_lo(lo), tot_hi(hi),
      unit_dat(unit_dat_), unit_op(unit_op_), add(add_), comp(comp_),
      appl(appl_) {
    node = new Node<DAT, OP>(/*lo_, hi_,*/ unit_dat, unit_op);
  }

  DAT node_query(Node<DAT, OP>* nd, ll lo, ll hi, ll left, ll right) {
    if (!nd) return unit_dat;
    if (hi <= left || right <= lo) return unit_dat;
    if (left <= lo && hi <= right) {
      return appl(hi - lo, nd->op, nd->val);
    }
    ll mid = (lo + hi) / 2;
    push(nd);
    DAT val1 = node_query(nd->lo_node, lo, mid, left, right);
    DAT val2 = node_query(nd->hi_node, mid, hi, left, right);
    return appl(hi - lo, nd->op, add(val1, val2));
  }

  DAT query(ll left, ll right) {
    return node_query(node, tot_lo, tot_hi, left, right);
  }

  void push(Node<DAT, OP>* nd) {
    if (!nd->lo_node) {
      nd->lo_node = new Node<DAT, OP>(unit_dat, nd->op);
    }else {
      nd->lo_node->op = comp(nd->op, nd->lo_node->op);
    }
    if (!nd->hi_node) {
      nd->hi_node = new Node<DAT, OP>(unit_dat, nd->op);
    }else {
      nd->hi_node->op = comp(nd->op, nd->hi_node->op);
    }
    nd->op = unit_op;
  }

  DAT node_update(Node<DAT, OP>* nd, ll lo, ll hi, ll left, ll right, OP f) {
    if (hi <= left || right <= lo) return appl(hi - lo, nd->op, nd->val);
    if (left <= lo && hi <= right) {
      nd->op = comp(f, nd->op);
      return appl(hi - lo, nd->op, nd->val);
    }
    ll mid = (lo + hi) / 2;
    push(nd);
    DAT val1 = node_update(nd->lo_node, lo, mid, left, right, f);
    DAT val2 = node_update(nd->hi_node, mid, hi, left, right, f);
    nd->val = add(val1, val2);
    DLOGK(lo, hi, val1, val2, nd->val);
    return nd->val;
  }

  void update(ll left, ll right, OP f) {
    node_update(node, tot_lo, tot_hi, left, right, f);
  }

  /* for debugging */
  void show_nodes() {
    ll seq = 1;
    auto sub = [&](auto rF, ll this_seq,
                   Node<DAT, OP>* nd, ll lo, ll hi) -> void {
      ll ts1 = 0, ts2 = 0;
      if (nd->lo_node) {
        ts1 = seq++;
        ts2 = seq++;
      }
      cerr << "{" << this_seq << "} [" << lo << ", " << hi << ") val="
           << nd->val << ", op=" << nd->op;
      if (ts1 > 0) {
        cerr << ", lo_node=" << ts1 << ", hi_node=" << ts2;
      }
      cerr << endl;
      if (ts1 > 0) {
        ll mid = (lo + hi) / 2;
        rF(rF, ts1, nd->lo_node, lo, mid);
        rF(rF, ts2, nd->hi_node, mid, hi);
      }
    };
    cerr << endl;
    sub(sub, seq++, node, tot_lo, tot_hi);
  }
  
};

template<typename DAT, typename OP>
auto make_dyn_seg_tree(ll lo_, ll hi_, DAT unit_dat, OP unit_op,
                       auto add, auto comp, auto appl)
  -> DynSegTree<DAT, OP, decltype(add), decltype(comp), decltype(appl)> {
  return DynSegTree(lo_, hi_, unit_dat, unit_op, add, comp, appl);
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  if (0) {
    using DAT = ll;
    using OP = optional<ll>;
    const DAT unit_dat = LLONG_MAX;
    const OP unit_op = nullopt;
    auto xAdd = [](DAT x, DAT y) -> DAT { return min(x, y); };
    auto xComp = [](OP h, OP g) -> OP { return h.has_value() ? h : g; };
    auto xAppl = [](int k, OP f, DAT x) -> DAT { return f.value_or(x); };
    auto dst = make_dyn_seg_tree(0, 64, unit_dat, unit_op, xAdd, xComp, xAppl);

    dst.update(11, 12, 100);
    // dst.show_nodes();
    dst.update(20, 21, 200);
    // dst.show_nodes();
    cout << dst.query(0, 64) << endl;
    cout << dst.query(0, 15) << endl;
    cout << dst.query(15, 30) << endl;
    cout << dst.query(30, 45) << endl;

  }

  if (1) {
    ll N, M, Q; cin >> N >> M >> Q;
    ll lim = 1e8 + 1;
    using DAT = ll;
    using OP = ll;
    const DAT unit_dat = 0;
    const OP unit_op = 0;
    auto xAdd = [](DAT x, DAT y) -> DAT { return x + y; };
    auto xAppl = [](int k, OP f, DAT x) -> DAT { return k * f + x; };
    auto xComp = [](OP h, OP g) -> OP { return h + g; };
    auto st_A_num = make_dyn_seg_tree(0, lim, unit_dat, unit_op, xAdd, xComp, xAppl);
    auto st_B_num = make_dyn_seg_tree(0, lim, unit_dat, unit_op, xAdd, xComp, xAppl);
    auto st_A_sum = make_dyn_seg_tree(0, lim, unit_dat, unit_op, xAdd, xComp, xAppl);
    auto st_B_sum = make_dyn_seg_tree(0, lim, unit_dat, unit_op, xAdd, xComp, xAppl);
    st_A_num.update(0, 1, N);
    st_B_num.update(0, 1, M);

    vector<ll> A(N), B(M);
    

    auto func = [&](auto& st_me_num, auto& st_me_sum,
                    auto& st_you_num, auto& st_you_sum,
                    auto& rec_me, ll x, ll vnew) -> ll {
      ll vold = rec_me[x];
      ll vmin = min(vold, vnew);
      ll vmax = max(vold, vnew);
      ll diff1 = st_you_num.query(0, vmin) * (vnew - vold);
      ll sum_middle = st_you_sum.query(vmin, vmax);
      ll sum_up = st_you_num.query(vmin, vmax) * vmax;
      ll diff2 = sum_up - sum_middle;
      if (vnew < vold) diff2 = -diff2;
      ll diff = diff1 + diff2;

      st_me_num.update(vold, vold + 1, -1);
      st_me_num.update(vnew, vnew + 1,  1);
      st_me_sum.update(vold, vold + 1, -vold);
      st_me_sum.update(vnew, vnew + 1,  vnew);
      rec_me[x] = vnew;

      return diff;
    };

    ll sum = 0;
    for (ll q = 0; q < Q; q++) {
      ll t, x, y; cin >> t >> x >> y; x--;
      ll diff = 0;
      if (t == 1) {
        diff = func(st_A_num, st_A_sum, st_B_num, st_B_sum, A, x, y);
      }else {
        diff = func(st_B_num, st_B_sum, st_A_num, st_A_sum, B, x, y);
      }
      sum += diff;
      cout << sum << "\n";

      for (ll p = 0; p <= 10; p++) {
        DLOGK(p, st_A_num.query(p, p+1));
        DLOGK(p, st_A_sum.query(p, p+1));
        DLOGK(p, st_B_num.query(p, p+1));
        DLOGK(p, st_B_sum.query(p, p+1));
      }

    }
  }

  return 0;
}

