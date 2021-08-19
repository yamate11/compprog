#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(suffixArray debug cmpNaive)

// ---- inserted library file suffixArray.cc

struct SuffixArray {
private:
  string str;

  /* arr and rank is automatically built, but lcp is not.
     Therefore, we make lcp private so that the user does not accidentally
     access unbuilt empty vector.
   */
  vector<int> lcp;  // lcp.size() == str.size()
  bool lcp_built;

public:
  vector<int> arr;  // arr.size() == str.size() + 1
  vector<int> rank; // rank.size() == str.size() + 1

  void init(string s) {
    str = s;
    lcp_built = false;
    int N = str.size();
    arr.resize(N + 1);
    rank.resize(N + 1);
    if (N == 0) return;
    if (N == 1) {
      arr.at(0) = rank.at(0) = 1;
      return;
    }
    copy(str.begin(), str.end(), rank.begin());
    rank.at(N) = 0;
    for (int k = 1; k < N; k *= 2) {
      iota(arr.begin(), arr.end(), 0);
      auto compare = [&](int p, int q) -> bool {
	if (p == q) return false;
	if (rank.at(p) != rank.at(q)) return rank.at(p) < rank.at(q);
	if (p + k > N) return true;
	if (q + k > N) return false;
	return rank.at(p + k) < rank.at(q + k);
      };
      sort(arr.begin(), arr.end(), compare);
      vector<int> tmp(N + 1);
      tmp.at(arr.at(0)) = 0;
      for (int i = 1; i <= N; i++) {
	int prev = arr.at(i-1);
	int cur = arr.at(i);
	tmp.at(cur) = tmp.at(prev) + (compare(prev, cur) ? 1 : 0);
      }
      rank = move(tmp);
    }
  }

  SuffixArray(string s) { init(s); }

  int at(int i) { return arr.at(i); }

  const vector<int>& getLcp() {
    if (lcp_built) return lcp;
    lcp_built = true;
    int N = str.size();
    lcp.resize(N);
    if (N <= 1)  return lcp;
    int h = 0;
    for (int i = 0; i < N; i++) {
      int ri = rank.at(i);
      assert(ri - 1 >= 0);
      int j = arr.at(ri - 1);
      if (h > 0) h--;
      while (j + h < N && i + h < N && str.at(j + h) == str.at(i + h)) h++;
      lcp.at(ri - 1) = h;
    }
    return lcp;
  }

};

// ---- end suffixArray.cc

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
  string S; cin >> S;

  auto f = [&](ll k, ll j) -> ll {
    ll i = 0;
    for ( ; k + i < N && j + i < N && S[k + i] == S[j + i]; i++);
    return i;
  };

  for (ll k = 0; k < N; k++) {
    ll val = 0;
    for (ll j = 0; j < N; j++) val += f(k, j);
    cout << val << "\n";
  }

  return 0;
}
int body(istream& cin, ostream& cout) {

  ll N; cin >> N;
  string S; cin >> S;
  SuffixArray sa(S);
  auto lcp = sa.getLcp();
  lcp.push_back(0);

  auto func = [&](const vector<int>& vec) -> vector<int> {
    using sta = pair<ll, ll>;
    vector<sta> stack;
    ll sz = vec.size();
    vector<int> ret(sz);
    ll val = 0;
    for (ll i = 0; i < sz; i++) {
      ll kk = 1;
      while (true) {
        if (stack.empty()) break;
        auto [v, k] = stack.back();
        if (v < vec[i]) break;
        stack.pop_back();
        val -= v * k;
        kk += k;
      }
      stack.emplace_back(vec[i], kk);
      val += vec[i] * kk;
      ret[i] = val;
    }
    return ret;
  };
  auto p1 = func(lcp);
  auto lcpRev(lcp);
  reverse(lcpRev.begin(), lcpRev.end());
  auto p2 = func(lcpRev);
  DLOGK(lcp);
  DLOGK(lcpRev);
  DLOGK(p1);
  DLOGK(p2);
  vector<ll> ans(N);
  for (ll i = 1; i <= N; i++) {
    ll j = sa.arr[i];
    ll a0 = N - j;
    ll a1 = p1[i - 1];
    ll a2 = p2[N - i];
    DLOGK(i, j, a0, a1, a2);
    ans[j] = a0 + a1 + a2;
  }
  for (ll i = 0; i < N; i++) cout << ans[i] << "\n";
  return 0;
}

