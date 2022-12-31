#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using ordered_set = tree<
  ll,
  null_type,
  less<ll>,
  rb_tree_tag,
  tree_order_statistics_node_update
  >;

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

template <typename T>
struct RBST {

  static random_device rd;
  static mt19937 rng;
  static int randrange(int i, int j) {
    uniform_int_distribution<int> dist(i, j - 1);
    return dist(rng);
  }

  struct Node {
    Node* left;
    Node* right;
    int size;
    T val;

    Node() : left(nullptr), right(nullptr), size(1), val() {}
    Node(const T& val_) : left(nullptr), right(nullptr), size(1), val(val_) {}
    Node(Node* left_, Node* right_, int size_, const T& val_) : left(left_), right(right_), size(size_), val(val_) {}
    ~Node() {
      if (left) delete left;
      if (right) delete right;
    }

    void _push() {}

    void _update() { size = _size_s(left) + _size_s(right) + 1; }

    static int _size_s(Node* p) { return p ? p->size : 0; }

    static int _lb_idx_s(Node* p, const T& v) { return p ? p->lb_idx(v) : 0; }
    int lb_idx(const T& v) const { return val < v ? _size_s(left) + 1 + _lb_idx_s(right, v) : _lb_idx_s(left, v); }
    
    static int _ub_idx_s(Node* p, const T& v) { return p ? p->ub_idx(v) : 0; }
    int ub_idx(T v) const { return v < val ? _ub_idx_s(left, v) : _size_s(left) + 1 + _ub_idx_s(right, v); }

    static bool _member_s(Node* p, const T& v) { return p ? p->member(v) : false; }
    bool member(const T& v) const {
      if (v < val) return _member_s(left, v);
      else if (val < v) return _member_s(right, v);
      else return true;
    }

    T at(int k) const {
      int lsz = _size_s(left);
      if (k < lsz) return left->at(k);
      k -= lsz;
      if (k == 0) return val;
      return right->at(k - 1);
    }

    static Node* _insert_s(Node* p, const T& v, bool decided) {
      if (not p) return new Node(v);
      return p->insert(v, decided);
    }
    Node* insert(const T& v, bool decided) {
      if (not decided and RBST::randrange(0, size + 1) == 0) decided = true;
      if (v < val) {
        Node* p = _insert_s(left, v, decided);
        if (not p) return nullptr;
        if (decided) {
          left = p->right;
          p->right = this;
          _update();
          p->_update();
          return p;
        }else {
          left = p;
          _update();
          return this;
        }
      }else if (val < v) {
        Node* p = _insert_s(right, v, decided);
        if (not p) return nullptr;
        if (decided) {
          right = p->left;
          p->left = this;
          _update();
          p->_update();
          return p;
        }else {
          right = p;
          _update();
          return this;
        }
      }else {
        return nullptr;
      }
    }

    static pair<Node*, Node*> _erase_s(Node* p, const T& v) {
      if (not p) return {nullptr, nullptr};
      return p->erase(v);
    }
    pair<Node*, Node*> erase(const T& v) {
      if (v < val) {
        auto [p, deleted] = _erase_s(left, v);
        if (not deleted) return {this, nullptr};
        left = p;
        _update();
        return {this, deleted};
      }else if (val < v) {
        auto [p, deleted] = _erase_s(right, v);
        if (not deleted) return {this, nullptr};
        right = p;
        _update();
        return {this, deleted};
      }else {
        Node* p = _merge_s(left, right);
        left = nullptr;
        right = nullptr;
        return {p, this};
      }
    }

    static Node* _merge_s(Node* p, Node* q) {
      if (not p) return q;
      if (not q) return p;
      ll n = _size_s(p);
      ll m = _size_s(q);
      if (RBST::randrange(0, n + m) < n) {
        Node* r = _merge_s(p->right, q);
        p->right = r;
        p->_update();
        return p;
      }else {
        Node* r = _merge_s(p, q->left);
        q->left = r;
        q->_update();
        return q;
      }
    }

    /*
    static Node* merge(Node* l, Node* r) {
      if (not l) return r;
      if (not r) return l;
      l->_push(); r->_push();
      if (Node::randrange(0, l->size + r->size) < l->size) {
        l->right = merge(l->right, r);
        l->_update();
        return l;
      }else {
        r->left = merge(l, r->left);
        r->_update();
        return r;
      }
    }

    using pnn = pair<Node*, Node*>;
    pnn split_base(optional<const T&> v, int k) {
      if ((not v) and (k < 0 or size <= k)) throw new runtime_error("Node.split: k is out of range");
      _push();
      if (not left) return right->split_base(v, k);
      if (not right) return left->split_base(v, k);
      if ((v and (not val < *v)) or k <= left->size) {
        auto [l1, r1] = left->split_base(v, k);
        left = r1;
        _update();
        return pnn(l1, this);
      } else {
        auto [l1, r1] = right->split_base(v, k - left->size - 1);
        right = l1;
        _update();
        return pnn(this, r1);
      }
    }

    // returns [0, k) and [k, N)
    prr split(int k) { return _split_base(nullopt, k); }
    */

#if DEBUG
    pair<string, int> show(int seq) const {
      stringstream ss;
      int seq0 = seq;
      string ptr_l = "null", ptr_r = "null";
      if (left) {
        ptr_l = to_string(seq + 1);
        string exp_l;
        tie(exp_l, seq) = left->show(seq + 1);
        ss << exp_l;
      }
      if (right) {
        ptr_r = to_string(seq + 1);
        string exp_r;
        tie(exp_r, seq) = right->show(seq + 1);
        ss << exp_r;
      }
      ss << seq0 << ": [left: " << ptr_l << ", right: " << ptr_r << ", size: " << size << ", val: " << val << "]\n";
      return {ss.str(), seq};
    }

    int depth() {return max(left ? left->depth() + 1 : 0, right ? right->depth() + 1 : 0);}
    double a_depth() {
      if (not left and not right) return 1.0;
      if (not left) return (1 + right->a_depth()) * right->size / (right->size + 1);
      if (not right) return (1 + left->a_depth()) * left->size / (left->size + 1);
      return ((1 + left->a_depth()) * left->size + (1 + right->a_depth()) * right->size) / (left->size + right->size + 1);
    }

#else
    string show(int seq) const { return ""; }
    int depth() { return 0; }
    double a_depth() { return 0.0; }
#endif

  };

  Node* node;

  RBST() : node(nullptr) {}
  RBST(const T& v) { node = new Node(v); }
  ~RBST() { if (node) delete node; }
  
  int size() const { return Node::_size_s(node); }
  int lb_idx(const T& v) const { return Node::_lb_idx_s(node, v); }
  int ub_idx(const T& v) const { return Node::_ub_idx_s(node, v); }
  T at(int k) const {
    if (k < 0 or size() <= k) throw new runtime_error("RBST.at: k is out of range");
    return node->at(k);
  }
  bool member(const T& v) const { return Node::_memeber_s(node, v); }
  bool insert(const T& v) {
    Node* p = Node::_insert_s(node, v, false);
    if (not p) return false;
    node = p;
    return true;
  }
  bool erase(const T& v) {
    if (not node) return false;
    auto [p, deleted] = Node::_erase_s(node, v);
    if (not deleted) return false;
    node = p;
    delete deleted;
    return true;
  }

#if DEBUG
  string show() const {
    if (not node) return "(empty)";
    auto [s, i] = node->show(1);
    return s;
  }
#else
  string show() const { return ""; }
#endif

  friend ostream& operator<<(ostream& os, const RBST& r) { return os << r.show(); }
};

template <typename T> random_device RBST<T>::rd;
template <typename T> mt19937 RBST<T>::rng(RBST<T>::rd());

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  if (0) {
    RBST<ll> t;
  
    t.insert(6);
    DLOGK(t);
    t.insert(2);
    DLOGK(t);
    t.insert(8);
    DLOGK(t);
    t.insert(4);
    DLOGK(t);
    t.insert(0);
    DLOGK(t);
    assert(t.at(2) == 4);
    assert(t.at(4) == 8);
    assert(t.lb_idx(6) == 3);
    assert(t.lb_idx(7) == 4);
    assert(t.ub_idx(4) == 3);
    assert(t.ub_idx(5) == 3);
    assert(t.size() == 5);
    t.erase(4);
    assert(t.size() == 4);
    t.erase(6);
    assert(t.size() == 3);
    t.erase(0);
    assert(t.size() == 2);
    t.erase(2);
    assert(t.size() == 1);
    t.erase(8);
    assert(t.size() == 0);
  }
  
  if (0) {
    RBST<ll> t;
    REP(i, 0, 10000) t.insert(i);
    cout << t.node->depth() << endl;
    cout << t.node->a_depth() << endl;
    REP(i, 10000, 1000000) t.insert(i);
    cout << t.node->depth() << endl;
    cout << t.node->a_depth() << endl;
    REP(i, 0, 990000) t.erase(i);
    cout << t.node->depth() << endl;
    cout << t.node->a_depth() << endl;
  }

  if (1) {
    
    bool pbds = false, rbst = false, ordi = true;
    if (argc >= 2 and string(argv[1]) == "pbds") pbds = true;
    if (argc >= 2 and string(argv[1]) == "rbst") rbst = true;
    if (argc >= 2 and string(argv[1]) == "set") ordi = true;

    ordered_set os;
    RBST<ll> ss;
    set<ll> us;
    ll N; cin >> N;
    if (pbds) {
      REP(i, 0, N) {
        ll tp, x; cin >> tp >> x;
        if (tp == 1) {
          os.insert(x);
        }else if (tp == 2) {
          os.erase(x);
        }else if (tp == 3) {
          cout << os.order_of_key(x) << "\n";
        }else if (tp == 4) {
          cout << *os.find_by_order(x) << "\n";
        }
      }
    }
    if (rbst) {
      REP(i, 0, N) {
        ll tp, x; cin >> tp >> x;
        if (tp == 1) {
          ss.insert(x);
        }else if (tp == 2) {
          ss.erase(x);
        }else if (tp == 3) {
          cout << ss.lb_idx(x) << "\n";
        }else if (tp == 4) {
          cout << ss.at(x) << "\n";
        }
      }
    }
    if (ordi) {
      REP(i, 0, N) {
        ll tp, x; cin >> tp >> x;
        if (tp == 1) {
          us.insert(x);
        }else if (tp == 2) {
          us.erase(x);
        }else {
          cout << "Sorry, not implemented." << endl;
          exit(1);
        }
      }
    }
  }

  return 0;
}
