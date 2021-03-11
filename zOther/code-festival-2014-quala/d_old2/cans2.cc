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

template <typename T>
ostream& operator<< (ostream& os, const set<T>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T>
ostream& operator<< (ostream& os, const multiset<T>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const map<T1, T2>& mp) {
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

// ---- end debug.cc
// @@ !! LIM  -- end mark --

int body(istream& cin, ostream& cout) {
  ll A, K; cin >> A >> K;

  vector<ll> vec;
  {
    ll x = A;
    while (x > 0) {
      ll a = x % 10;
      vec.push_back(a);
      x /= 10;
    }
  }
  ll n = (ll)vec.size();
  vector<bool> digits(10);
  ll i0 = -1, iLast = -1;
  {
    ll i = n-1;
    ll d = -1;
    for (; K >= 0 && i >= 0; i--) {
      d = vec.at(i);
      if (!digits.at(d)) {
	if (K == 0) break;
	digits.at(d) = true;
	if (K == 1) iLast = i;
	K--;
      }
    }
    if (i < 0) {
      cout << 0 << endl;
      return 0;
    }
    i0 = i;
  }
  DLOG("i0=", i0, "iLast=", iLast);
  DLOG("digits=", digits);
  auto findLo = [&](ll d) -> ll {
    for (ll j = d - 1; j >= 0; j--) if (digits.at(j)) return j;
    return -1;
  };
  auto computeDiff = [&](ll x, ll i, ll m) -> ll {
    DLOG("computeDiff", x, i, m);
    for (; i >= 0; i--)  x = 10 * x + m - vec.at(i);
    DLOG("computeDiff returns", x);
    return x;
  };
  auto getDiffLo = [&]() -> ll {
    ll md = findLo(10);
    DLOG("getDiffLo: md = ", md);
    for (ll i = i0; i < iLast; i++) {
      ll jj = findLo(vec.at(i));
      DLOG("getDiffLo: jj = ", jj, "i=", i);
      if (jj >= 0) return computeDiff(jj - vec.at(i), i - 1, md);
    }
    ll dd = vec.at(iLast);
    assert(dd > 0);
    ll m = digits.at(dd - 1) || (dd == 1 && iLast == n - 1) ? 9 : md != dd ? md : md - 1;
    return computeDiff(-1, iLast - 1, m);
  };

  auto findHi = [&](ll d) -> ll {
    for (ll j = d + 1; j < 10; j++) if (digits.at(j)) return j;
    return -1;
  };
  auto getDiffHi = [&]() -> ll {
    ll md = findHi(-1);
    for (ll i = i0; i < iLast; i++) {
      ll jj = findHi(vec.at(i));
      if (jj >= 0) return computeDiff(jj - vec.at(i), i - 1, md);
    }
    ll dd = vec.at(iLast);
    assert(dd < 9);
    ll m = digits.at(dd + 1) ? 0 : md != dd ? md : dd + 1;
    return computeDiff(1, iLast - 1, m);
  };
  ll diffLo = -getDiffLo();
  ll diffHi = getDiffHi();
  cout << min(diffLo, diffHi) << endl;
  return 0;
}

int naive(istream& cin, ostream& cout) {
  ll A, K; cin >> A >> K;

  auto numDigits = [&](ll x) -> ll {
    if (x == 0) return 1;
    vector<char> dgs(10);
    ll cnt = 0;
    while (x > 0) {
      ll y = x % 10;
      if (!dgs.at(y)) {
	dgs.at(y) = 1;
	cnt++;
      }
      x /= 10;
    }
    return cnt;
  };

  ll best = 3*A;
  for (ll x = 0; x < 2 * A; x++) {
    if (numDigits(x) > K) continue;
    best = min(best, abs(A - x));
  }
  cout << best << endl;
  return 0;
  
}


const string end_mark("^__=end=__^");
const string end_file_mark("^__=end_file=__^");

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
      DLOG("starts body with: ", ss_in.str());
      body(ss_in, ss_out);
    }else {
      DLOG("starts naive with: ", ss_in.str());
      naive(ss_in, ss_out);
    }
    cout << ss_out.str() << end_mark << endl;
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  DLOG("./cans starts!!!!!!!!!!!!!!!!!!!");
#if CMPNAIVE
  if (argc == 2) {
    if (strcmp(argv[1], "cmpNaive") == 0) {
      DLOG("./cans cmpNaive");
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

