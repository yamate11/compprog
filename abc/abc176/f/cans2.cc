#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:updMaxMin cmpNaive perm debug)
// --> f:updMaxMin cmpNaive perm f:<< debug
// ---- inserted function updMaxMin from util.cc
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
// ---- end updMaxMin
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
// ---- inserted library file perm.cc

template<typename T>
class IterPerm {
  int cand_size;
  int seq_size;
  T perm;
  vector<T> cands;
  vector<int> idx;
  
  void construct(const T& orig, int ss) {
    cand_size = orig.size();
    seq_size = ss;
    perm = T(orig.begin(), orig.begin() + seq_size);
    cands = vector<T>(seq_size);
    if (seq_size > 0) cands.at(0) = orig;
    idx = vector<int>(seq_size);
    init();
  }

  void init() {
    for (int i = 0; i < seq_size; i++) {
      perm.at(i) = cands.at(0).at(i);
      if (i > 0) {
	cands.at(i) = T(cands.at(0).begin() + i, cands.at(0).end());
      }
      idx.at(i) = 0;
    }
  }

  // IntPerm is implemented using IterPerm<vector<int>>, and
  // it needs a constructor without parameter.
  friend class IntPerm;
  IterPerm() {}

public:
  
  IterPerm(const T& orig, int ss) { construct(orig, ss); }
  IterPerm(const T& orig) { construct(orig, orig.size()); }
  
  const T& get() { return perm; }

  bool next() {
    int i = seq_size - 1;
    while (i >= 0 && ++idx.at(i) >= cand_size - i) i--;
    if (i < 0) {
      init();
      return false;
    }
    perm.at(i) = cands.at(i).at(idx.at(i));
    for (int k = i + 1; k < seq_size; k++) {
      for (int m = 0; m < cand_size - k; m++) {
	int shift = m < idx.at(k - 1) ? 0 : 1;
	cands.at(k).at(m) = cands.at(k - 1).at(m + shift);
      }
      idx.at(k) = 0;
      perm.at(k) = cands.at(k).at(0);
    }
    return true;
  }
};

class IntPerm {

  IterPerm<vector<int>> itp;

  void construct(int ns, int ss) {
    vector<int> vec(ns);
    iota(vec.begin(), vec.end(), 0);
    itp = IterPerm(vec, ss);
  }

public:

  IntPerm(int ns, int ss) { construct(ns, ss); }
  IntPerm(int ns) { construct(ns, ns); }
  const vector<int>& get() { return itp.get(); }
  bool next() { return itp.next(); }

};

template<typename T>
class IterComb {

  vector<T> orig;
  int c_size;
  vector<T> comb;
  vector<int> idx;

  void init() {
    for (int i = 0; i < c_size; i++) {
      idx.at(i) = i;
      comb.at(i) = orig.at(i);
    }
  }


public:

  IterComb() {}

  IterComb(vector<T> orig_, int c_size_)
    : orig(orig_), c_size(c_size_), comb(c_size), idx(c_size) { init(); }

  const vector<T>& get() { return comb; }

  bool next() {
    int n = orig.size();
    int i = c_size - 1;
    while (i >= 0 && ++idx.at(i) > n - (c_size - i)) i--;
    if (i < 0) {
      init();
      return false;
    }

    int k = idx.at(i);
    for ( ; i < c_size; i++, k++) {
      idx.at(i) = k;
      comb.at(i) = orig.at(k);
    }
    return true;

  }

};

class IntComb {
  
  IterComb<int> itc;

public:

  IntComb(int n, int r) {
    vector<int> seq(n);
    iota(seq.begin(), seq.end(), 0);
    itc = IterComb<int>(seq, r);
  }
  const vector<int>& get() { return itc.get(); }
  bool next() { return itc.next(); }
};

// ---- end perm.cc
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
// @@ !! LIM  -- end mark --


int naive(istream& cin, ostream& cout) {
  
  ll N; cin >> N;
  vector<ll> A(3*N);
  for (ll i = 0; i < 3 * N; i++) {
    ll a; cin >> a; a--;
    A[i] = a;
  }

  auto dfs = [&](auto rF, ll dep, ll p, ll q, ll acc) -> ll {
    if (dep == N-1) {
      if (p == q && p == A[3*N - 1]) return acc + 1;
      else return acc;
    }
    IntComb ic(5, 2);
    vector vec({p, q, A[3*dep + 2], A[3*dep + 3], A[3*dep + 4]});
    const vector<int>& v = ic.get();
    ll ret = 0;
    do {
      vector<int> chosen(v);
      sort(chosen.begin(), chosen.end());
      ll prev = -1;
      vector<ll> pass;
      ll idx = 0;
      int fail = 0;
      for (ll j = 0; j < 5; j++) {
	if (idx < 2 && chosen[idx] == j) {
	  pass.push_back(vec[j]);
	  idx++;
	}else {
	  if (prev == -1) {
	    prev = vec[j];
	  }else if (prev != vec[j]) {
	    fail = 1;
	  }
	}
      }
      ll t = rF(rF, dep + 1, pass[0], pass[1], acc + (1 - fail));
      updMax(ret, t);
    }while (ic.next());
    return ret;
  };
  ll ans = dfs(dfs, 0, A[0], A[1], 0);
  cout << ans << endl;
  return 0;
}
int body(istream& cin, ostream& cout) {

  ll N; cin >> N;
  vector<ll> A(3*N);
  for (ll i = 0; i < 3 * N; i++) {
    ll a; cin >> a; a--;
    A[i] = a;
  }
  ll big = 1e9;
  ll tbl0 = -big;
  vector tbl1(N, -big);
  vector __tbl2(N, vector(N, -big));
  auto tbl2 = [&](ll p, ll q) -> ll& {
    if (p > q) swap(p, q);
    return __tbl2[p][q];
  };

  tbl2(A[0], A[1]) = 0;
  tbl1[A[0]] = 0;
  tbl1[A[1]] = 0;
  tbl0 = 0;
  
  ll threeC = 0;
  using sta = tuple<ll, ll, ll>;
  //               (newval, arg1, arg2)
  for (ll i = 0; i < N-1; i++) {
    vector<sta> updates;
    ll p = A[3*i + 2], q = A[3*i + 3], r = A[3*i + 4];
    if (p == q && q == r) {
      threeC++;
      continue;
    }
    if (p == q || q == r || p == r) {
      ll a, b;
      if      (p == q) { a = p; b = r; }
      else if (q == r) { a = q; b = p; }
      else if (p == r) { a = p; b = q; }
      else    assert(0);
      for (ll z = 0; z < N; z++) {
	ll newval = tbl2(a, z) + 1;
	updates.emplace_back(newval, z, b);
	updates.emplace_back(newval, z, -1);
	updates.emplace_back(newval, b, -1);
	updates.emplace_back(newval, -1, -1);
      }
    }
    for (ll j = 0; j < 3; j++) {
      ll s = A[3*i + 2 + j];
      ll t = A[3*i + 2 + ((j + 1) % 3)];
      ll u = A[3*i + 2 + ((j + 2) % 3)];;
      ll newval = tbl2(s, s) + 1;
      updates.emplace_back(newval, t, u);
      updates.emplace_back(newval, t, -1);
      updates.emplace_back(newval, u, -1);
      updates.emplace_back(newval, -1, -1);
    }
    for (ll z = 0; z < N; z++) {
      for (ll j = 0; j < 3; j++) {
	ll s = A[3*i + 2 + j];
	updates.emplace_back(tbl1[z], s, z);
	updates.emplace_back(tbl1[z], s, -1);
      }
    }
    updates.emplace_back(tbl0, p, q);
    updates.emplace_back(tbl0, q, r);
    updates.emplace_back(tbl0, p, r);
    updates.emplace_back(tbl0, p, -1);
    updates.emplace_back(tbl0, q, -1);
    updates.emplace_back(tbl0, r, -1);
    
    for (auto [val, a1, a2] : updates) {
      if      (a1 < 0) updMax(tbl0, val);
      else if (a2 < 0) updMax(tbl1[a1], val);
      else             updMax(tbl2(a1, a2), val);
    }
    DLOG("tbl0=", tbl0);
    DLOG("tbl1=", tbl1);
    DLOG("tbl2=", __tbl2);
  }
  ll p = A[3*N - 1];
  updMax(tbl0, tbl2(p, p) + 1);
  tbl0 += threeC;
  cout << tbl0 << endl;

  return 0;
}

