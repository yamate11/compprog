#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(binsearch cmpNaive debug)
// --> binsearch cmpNaive f:<< debug
// ---- inserted library file binsearch.cc

template<typename T>
T binsearch(auto check, T yes, T no, T err = (T)1) {
  while (abs(yes - no) > err) {
    T mid = (yes + no) / (T)2;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

// ---- end binsearch.cc
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
  
  ll n; cin >> n;
  vector<ll> A(n);
  for (ll i = 0; i < n; i++) cin >> A[i];

  auto judge = [&]() -> bool {

    auto sub = [&](const auto& vec) -> bool {
      ll incLast = -1;
      ll decLast = 1e10;
      for (ll i = 0; i < n; i++) {
	if (vec[i] == 1) {
	  if (decLast <= A[i]) return false;
	  decLast = A[i];
	}else {
	  if (incLast >= A[i]) return false;
	  incLast = A[i];
	}
      }
      return true;

    };

    string bans; cin >> bans;
    if (bans == "YES") {
      vector<ll> bvec(n);
      for (ll i = 0; i < n; i++) cin >> bvec[i];
      return sub(bvec);
    }else if (bans == "NO") {

      for (ll x = 0; x < (1LL << n); x++) {
	vector<ll> evec(n);
	for (ll i = 0; i < n; i++) evec[i] = ((x >> i) & 1);
	if (sub(evec)) return false;
      }
      return true;

    }else return false;

  };


  cout << (judge() ? "OK\n" : "NG\n");
  return 0;


  return 0;
}
int body(istream& cin, ostream& cout) {

  ll n; cin >> n;
  vector<ll> A(n);
  for (ll i = 0; i < n; i++) cin >> A[i];
  ll lim = 2e5;
  
  auto check = [&](ll bnd) -> bool {
    ll stage = 0;
    ll prev = -1;
    for (ll i = 0; i < n; i++) {
      if (A[i] < bnd) continue;
      if (stage == 0) {
	prev = A[i];
	stage = 1;
      }else if (stage == 1) {
	if (prev <= A[i]) {
	  stage = 2;
	}
	prev = A[i];
      }else if (stage == 2) {
	if (prev >= A[i]) return false;
	prev = A[i];
      }
    }
    return true;
  };

  ll bnd = binsearch<ll>(check, lim, -1);
  DLOG("bnd=", bnd);

  ll stage = 0;
  vector<ll> ans(n);
  ll decLast = 1e10;
  ll incLast = -1;
  for (ll i = 0; i < n; i++) {
    if (stage == 0) {
      if (A[i] >= bnd) {
	if (decLast > A[i]) {
	  ans[i] = 1;
	  decLast = A[i];
	}else {
	  stage = 1;
	  ans[i] = 0;
	  incLast = A[i];
	}
      }else {
	if (incLast < A[i]) {
	  ans[i] = 0;
	  incLast = A[i];
	}else {
	  stage = 1;
	  ans[i] = 1;
	  decLast = A[i];
	}
      }
    } else if (stage == 1) {
      if (A[i] >= bnd) {
	if (incLast >= A[i]) {
	  cout << "NO\n";
	  return 0;
	}
	ans[i] = 0;
	incLast = A[i];
      }else {
	if (decLast <= A[i]) {
	  cout << "NO\n";
	  return 0;
	}
	ans[i] = 1;
	decLast = A[i];
      }
    }
  }
  cout << "YES\n";
  for (ll i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << ans[i];
  }
  cout << endl;

  return 0;
}

