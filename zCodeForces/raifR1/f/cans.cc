#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug segTree cmpNaive)
// --> f:<< debug segTree cmpNaive
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
void dbgLog(Head&& head) {
  cerr << head << endl;
}

template <class Head, class... Tail>
void dbgLog(Head&& head, Tail&&... tail)
{
  cerr << head << " ";
  dbgLog(forward<Tail>(tail)...);
}

#if DEBUG
  #define DLOG(...)        dbgLog(__VA_ARGS__)
  #define DFMT(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DFMT(...)
  #define DCALL(func, ...)
#endif

#if DEBUG_LIB
  #define DLOG_LIB(...)        dbgLog(__VA_ARGS__)
  #define DFMT_LIB(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL_LIB(func, ...) func(__VA_ARGS__)
#else
  #define DLOG_LIB(...)
  #define DFMT_LIB(...)
  #define DCALL_LIB(func, ...)
#endif

// ---- end debug.cc
// ---- inserted library file segTree.cc

// It seems that we should keep the size power of two,
// considering the binary search.

template <typename DAT, typename OP,
	  typename Fadd, typename Fcomp, typename Fappl> 
struct SegTree {
  int size;	     // power of two; >= 2
  int height;        // size = 1 << height;
  vector<DAT> node;  // vector of size 2*size.
                     // 0                 : unused
                     // 1    ... size-1   : interval
                     // size ... 2*size-1 : leaf
  vector<OP> susp;   // vector of size size.
                     // suspended operation FOR CHILDREN
                     // (already applied to this node)
  DAT unit_dat;
  OP unit_op;
  Fadd add;
  Fcomp comp;
  Fappl appl;
  bool range_update;
    
  SegTree(DAT unit_dat_, OP unit_op_, Fadd add_, Fcomp comp_, Fappl appl_,
	  bool range_update_)
    // , vector<DAT> initdat) 
    : unit_dat(unit_dat_), unit_op(unit_op_), add(add_), comp(comp_),
      appl(appl_), range_update(range_update_) {}

  void set_data(vector<DAT> initdat) {
    if (initdat.size() <= 0) {
      cerr << "the size of initial vector must be >= 1" << endl;
      abort();
    }
    if (initdat.size() == 1) {
      height = 0;
    }else {
      height = sizeof(int) * 8 - __builtin_clz(initdat.size() - 1);
    }
    size = 1 << height;
    node.resize(2*size, unit_dat);
    for (int i = 0; i < (int)initdat.size(); i++) {
      node.at(size + i) = initdat.at(i);
    }
    for (int t = size - 1; t >= 1; t--) {
      node.at(t) = add(node.at(t<<1|0), node.at(t<<1|1));
    }
    susp.resize(size, unit_op);
  }

  void child_updated_sub(int k, int t) {
    node.at(t) = appl(k, susp.at(t),
		      add(node.at(t<<1|0), node.at(t<<1|1)));
  }

  void child_updated(int l, int r) {
    int k = 1;
    r--;
    while (l > 1) {
      l >>= 1;
      r >>= 1;
      k *= 2;
      child_updated_sub(k, l);
      if (l < r) child_updated_sub(k, r);
    }
  }

  void node_op(int i, int k, OP f) {
    node.at(i) = appl(k, f, node.at(i));
    if (i < size) susp.at(i) = comp(f, susp.at(i));
  }

  void push_one(int i, int k) {
    node_op(i<<1|0, k / 2, susp.at(i));
    node_op(i<<1|1, k / 2, susp.at(i));
    susp.at(i) = unit_op;
  }

  void push_upto(int l, int r) {
    for (int s = height; s >= 1; s--) {
      int lz = l >> s;
      int rz = (r-1) >> s;
      int k = 1 << s;
      push_one(lz, k);
      if (lz < rz) push_one(rz, k);
    }
  }

  DAT query(int l, int r) {
    // DLOG("l=", l, "r=", r);
    if (l >= r) return unit_dat;
    DAT ret_l = unit_dat;
    DAT ret_r = unit_dat;
    // DLOG("1: ret_l=", ret_l, "ret_r", ret_r);
    l += size;
    r += size;
    if (range_update) push_upto(l, r);
    while (l < r) {
      if (l & 1) {
	ret_l = add(ret_l, node.at(l));
	// DLOG("l=", l, "ret_l=", ret_l);
	l++;
      }
      if (r & 1) {
	ret_r = add(node.at(r-1), ret_r);
	// DLOG("r=", r, "ret_r=", ret_r);
      }
      l >>= 1;
      r >>= 1;
    }
    DAT ret = add(ret_l, ret_r);
    // DLOG("ret_l=", ret_l, "ret_r", ret_r, "ret", ret);
    return ret;
  }

  void single_update(int i, OP f) {
    update(i, i+1, f);
  }

  void update(int l, int r, OP f) {
    // DLOG("update. 1. node=", node);
    if (l >= r) return;
    if ((! range_update) && (l + 1 < r)) {
      cerr << "FATAL: r - l >= 2 without setting range_update." << endl;
      abort();
    }
    l += size;
    r += size;
    if (range_update) push_upto(l, r);
    // DLOG("update. 2. node=", node);
    int l0 = l, r0 = r;
    int k = 1;
    while (l < r) {
      if (l & 1) {
	node_op(l, k, f);
	l++;
      }
      if (r & 1) {
	node_op(r-1, k, f);
      }
      l >>= 1;
      r >>= 1;
      k *= 2;
    }
    // DLOG("update. 3. node=", node);
    child_updated(l0, r0);
    // DLOG("node=", node);
    // DLOG("susp=", susp);
  }


  // Returns the least r >= l s.t. check(Add(v[l], ..., v[r-1])) == true,
  //    where check :: DAT -> bool
  // If there is no such r, returns -1.
  int binsearch_l(const auto& check, int l) {
    // DLOG("binsearch_l; l=", l);
    int x = l + size;
    DAT val = unit_dat;
    if (check(val)) return l;
    // DLOG("pt1");
    if (range_update) push_upto(x, x+1);
    int k = 1;
    while (true) {
      DAT t = add(val, node.at(x));
      if (check(t)) break;
      if (x & 1) {
	val = t;
	x++;
	if (__builtin_popcount(x) == 1) return -1;
      }
      x >>= 1;
      k <<= 1;
      // DLOG("  x=", x, "val=", val);
    }
    // DLOG("pt2; x=", x, "k=", k);
    while (k > 1) {
      if (range_update) push_one(x, k);
      DAT t = add(val, node.at(x<<1|0));
      if (check(t)) {
	x = (x<<1|0);
      }else {
	x = (x<<1|1);
	val = t;
      }
      k >>= 1;
    }
    // DLOG("pt3; x=", x, "k=", k);
    return x + 1 - size;
  }

};

template<typename DAT, typename OP>
auto make_seg_tree(DAT unit_dat, OP unit_op,
		   auto add, auto comp, auto appl,
		   bool range_update)
  -> SegTree<DAT, OP, decltype(add), decltype(comp), decltype(appl)> {
  return SegTree(unit_dat, unit_op, add, comp, appl, range_update);
}

// ---- end segTree.cc
// ---- inserted library file cmpNaive.cc

const string end_mark("^__=end=__^");
const string end_file_mark("^__=end_file=__^");

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
// @@ !! LIM  -- end mark --

int naive(istream& cin, ostream& cout) {
  ll n; cin >> n;
  string s; cin >> s;

  auto func = [&](ll l, ll r) -> ll {
    string t = s.substr(l, r - l);
    ll ret = 0;
    ll c = 0;
    for (ll i = 0; i < (ll)t.size(); i++) {
      if (t[i] == '0') {
	ret = max(ret, c);
	c = 0;
      }else {
	c++;
      }
    }
    ret = max(ret, c);
    // DLOG("t=", t, "ret=", ret);
    return ret;
  };

  ll ans = 0;
  for (ll l = 0; l < n; l++) {
    for (ll r = l + 1; r <= n; r++) {
      ans += func(l, r);
    }
  }
  cout << ans << endl;

  return 0;
}
int body(istream& cin, ostream& cout) {

  ll n; cin >> n;
  string s; cin >> s;
  ll ans = 0;
  ll cur = 0;
  ll streak = 0;

  using DAT = ll;
  using OP = ll;
  const DAT unit_dat = 0;
  const OP unit_op = 0;
  auto xAdd = [](DAT x, DAT y) -> DAT { return x + y; };
  auto xAppl = [](int k, OP f, DAT x) -> DAT { return k * f + x; };
  auto xComp = [](OP h, OP g) -> OP { return h + g; };
  auto st = make_seg_tree(unit_dat, unit_op, xAdd, xComp, xAppl, true);
  
  vector<ll> init(n + 1, n);
  st.set_data(init);

  for (ll i = n - 1; i >= 0; i--) {
    if (s[i] == '0') {
      ans += cur;
      streak = 0;
      continue;
    }
    streak++;
    ll m = st.query(streak, streak + 1) - i;
    cur += m;
    ans += cur;
    st.update(1, streak, -1);
    st.update(streak, streak + 1, i + streak - 1 - (m + i));
    // for (ll j = 1; j <= streak; j++) vec[j] = i + j - 1;
  }
  cout << ans << endl;

  return 0;
}

