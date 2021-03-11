#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug cmpNaive f:power)
// --> f:<< debug cmpNaive f:power
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
// ---- inserted function power from util.cc
/* *** WARNING ***  
      ll x = power(10, 12) 
   does not work since it is interpreted as 
      ll x = power<int>((int)10, 12)
   Use power<ll>(10, 12) or power(10LL, 12).
 */
template<typename T>
T power(T a, ll b) {
  T twoPow = a;
  T rv(1);
  while (b > 0) {
    if (b & 1LL) rv *= twoPow;
    twoPow *= twoPow;
    b >>= 1;
  }
  return rv;
}

// ad-hoc power function
template<typename T, typename Op>
T ah_power(T a, ll b, const T& unit_t, Op op) {
  T two_pow = a;
  T ret = unit_t;
  while (b > 0) {
    if (b & 1LL) ret = op(ret, two_pow);
    two_pow = op(two_pow, two_pow);
    b >>= 1;
  }
  return ret;
}
// ---- end power
// @@ !! LIM  -- end mark --

int naive(istream& cin, ostream& cout) {
  
  ll n, m; cin >> n >> m;
  vector<ll> A(n);
  for (ll i = 0; i < n; i++) {
    ll a; cin >> a;
    A[i] = a;
  }
  ll fcM, fcN; cin >> fcM >> fcN;
  vector<ll> FC(n);
  for (ll i = 0; i < n; i++) {
    cin >> FC[i];
    if (!(1 <= FC[i] && FC[i] <= m)) {
      cout << "NG\n";
      return 0;
    }
  }

  ll amax = 0;
  ll numchg = -1;
  for (ll x = 0; x < power<ll>(m, n); x++) {
    vector<ll> B(n);
    ll y = x;
    vector<ll> cnt(m+1);
    for (ll i = 0; i < n; i++) {
      B[i] = y % m + 1;
      cnt[B[i]] ++;
      y /= m;
    }
    ll xx = 1e10;
    for (ll i = 1; i <= m; i++) xx = min(xx, cnt[i]);
    if (xx > amax) {
      amax = xx;
      ll nc = 0;
      for (ll i = 0; i < n; i++) if (A[i] != B[i]) nc++;
      numchg = nc;
    }else if (xx == amax) {
      ll nc = 0;
      for (ll i = 0; i < n; i++) if (A[i] != B[i]) nc++;
      if (nc < numchg) {
	numchg = nc;
      }
    }
  }
  if (fcM != amax) {
    cout << "NG\n";
    return 0;
  }else if (fcN != numchg) {
    cout << "NG\n";
    return 0;
  }
  ll z = 0;
  for (ll i = 0; i < n; i++) if (A[i] != FC[i]) z++;
  if (z != fcN) {
    cout << "NG\n";
    return 0;
  }
  vector<ll> cntF(m+1);
  for (ll i = 0; i < n; i++) {
    cntF[FC[i]]++;
  }
  ll y = 1e5;
  for (ll i = 1; i <= m; i++) {
    y = min(y, cntF[i]);
  }
  if (y != fcM) {
    cout << "NG\n";
    return 0;
  }
  cout << "OK\n";


  return 0;


}


int body(istream& cin, ostream& cout) {

  ll n, m; cin >> n >> m;
  vector<ll> A(n);
  vector<ll> cnt(m+1);
  ll other = 0;
  for (ll i = 0; i < n; i++) {
    ll a; cin >> a;
    A[i] = a;
    if (a <= m) cnt[a]++;
    else other++;
  }
  ll t = n / m;
  // ll ss = m - (n % m) ;
  vector<ll> chg(m+1);
  ll sumchg = 0;
  for (ll i = 1; i <= m; i++) {
    if (cnt[i] < t) {
      chg[i] = t - cnt[i];
      sumchg += chg[i];
    }
  }
  if (sumchg > other) {
    ll rem = sumchg - other;
    for (ll i = 1; i <= m && rem > 0; i++) {
      if (cnt[i] > t) {
	ll z = min(cnt[i] - t, rem);
	chg[i] = -z;
	rem -= z;
      }
    }
    assert(rem == 0);
  }else if (sumchg < other) {
    // chg[1] += other - sumchg;
  }
  DLOG("chg=", chg);
  vector<ll> ans(n);
  ll p = 0;
  ll cngd = 0;
  for (ll i = 0; i < n; i++) {
    if (A[i] <= m && chg[A[i]] >= 0) {
      ans[i] = A[i];
    }else {
      while (p <= m && chg[p] <= 0) p++;
      if (p <= m) {
	ans[i] = p;
	chg[p]--;
	cngd++;
	if (A[i] <= m) chg[A[i]]++;
      }else {
	ans[i] = A[i];
      }
    }
  }
  cout << t << " " << cngd << endl;
  for (ll i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << ans[i];
  }
  cout << endl;


  return 0;
}

