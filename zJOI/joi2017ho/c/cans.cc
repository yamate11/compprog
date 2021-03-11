#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(binsearch debug cmpNaive)
// --> binsearch f:<< debug cmpNaive
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


// ---- end cmpNaive.cc
// @@ !! LIM  -- end mark --

int naive(istream& cin, ostream& cout) {
  ll H, W; cin >> H >> W;
  vector A(H, vector(W, 0LL));
  for (ll i = 0; i < H; i++) {
    for (ll j = 0; j < W; j++) {
      cin >> A[i][j];
    }
  }
  vector bder(H, 0LL);
  ll ans = 1e12;
  auto calc = [&]() -> void {
    ll maxL = -1, maxR = -1, minL = 1e12, minR = 1e12;
    for (ll p = 0; p < H; p++) {
      for (ll q = 0; q < W; q++) {
	ll x = A[p][q];
	if (q < bder[p]) {
	  maxL = max(maxL, x);
	  minL = min(minL, x);
	}else {
	  maxR = max(maxR, x);
	  minR = min(minR, x);
	}
      }
    }
    if (maxL == -1 || maxR == -1) return;
    ans = min(ans, max(maxL - minL, maxR - minR));
  };
  auto sch1 = [&](auto rF, ll i) -> void {
    if (i < H) {
      for (ll j = (i == 0 ? 0 : bder[i - 1]); j <= W; j++) {
	bder[i] = j;
	rF(rF, i + 1);
      }
    }else calc();
  };
  auto sch2 = [&](auto rF, ll i) -> void {
    if (i < H) {
      for (ll j = 0; j <= (i == 0 ? W : bder[i - 1]); j++) {
	bder[i] = j;
	rF(rF, i + 1);
      }
    }else calc();
  };
  sch1(sch1, 0);
  sch2(sch2, 0);
  cout << ans << endl;
  return 0;
}
int body(istream& cin, ostream& cout) {

  ll H, W; cin >> H >> W;
  vector A(H, vector(W, 0LL));
  ll amin = 1e12;
  ll amax = 0;
  for (ll i = 0; i < H; i++) {
    for (ll j = 0; j < W; j++) {
      cin >> A[i][j];
      amin = min(amin, A[i][j]);
      amax = max(amax, A[i][j]);
    }
  }
  DLOG("amin=", amin, "amax=", amax);
  vector<ll> hs_asc(H);
  iota(hs_asc.begin(), hs_asc.end(), 0);
  vector hs_desc(hs_asc); reverse(hs_desc.begin(), hs_desc.end());
  auto check = [&](ll diff) -> bool {
    DLOG("*** check is called.  diff=", diff);
    auto judge_big   = [&](ll x) -> bool { return x - amin > diff; };
    auto judge_small = [&](ll x) -> bool { return amax - x > diff; };
    auto sub = [&] (const auto& hs, auto judge1, auto judge2) -> bool {
      ll bder = W;
      for (ll i : hs) {
	for (ll j = 0; j < W; j++) {
	  if (j < bder) {
	    if (judge1(A[i][j])) {
	      if (judge2(A[i][j])) {
		DLOG("return false; i=", i, "j=", j);
		return false;
	      }
	      bder = j;
	      DLOG("i=", i, "bder=", bder);
	    }
	  }else {
	    if (judge2(A[i][j])) {
	      DLOG("return false; i=", i, "j=", j);
	      return false;
	    }
	  }
	}
      }
      return true;
    };
    bool b0 = sub(hs_asc,  judge_big,   judge_small);
    if (b0) {
      DLOG("return True; b0");
      return true;
    }
    bool b1 = sub(hs_desc, judge_big,   judge_small);
    if (b1) {
      DLOG("return True; b1");
      return true;
    }
    bool b2 = sub(hs_asc,  judge_small, judge_big);
    if (b2) {
      DLOG("return True; b2");
      return true;
    }
    bool b3 = sub(hs_desc, judge_small, judge_big);
    if (b3) {
      DLOG("return True; b2");
      return true;
    }
    return false;
  };
  ll ans = binsearch<ll>(check, amax - amin, -1);
  cout << ans << endl;

  return 0;
}

