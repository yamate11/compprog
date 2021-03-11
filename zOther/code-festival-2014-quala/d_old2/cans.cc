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

  ll best = A * 10;
  ll used = 0;
  for (ll i = n-1; i >= 0; i--) {
    ll d0 = vec.at(i);
    // if (d0 == 7) d0 = 10 / (d0 - 7);
    for (ll d = 0; d < 10; d++) {
      if (d == d0) continue;
      ll diff1 = d - d0;
      ll used2 = used + ((digits.at(d) || (d == 0 && i == n-1)) ? 0 : 1);
      if (used2 > K) continue;
      for (ll e = 0; e < 10; e++) {
	ll used3 = used2 + ((d == e || digits.at(e)) ? 0 : 1);
	if (used3 > K) continue;
	ll diff = diff1;
	for (ll j = i - 1; j >= 0; j--) {
	  diff = 10 * diff + e - vec.at(j);
	}
	best = min(best, abs(diff));
      }
    }
    if (!digits.at(d0)) {
      digits.at(d0) = true;
      used++;
      if (used > K) break;
    }
    if (i == 0) best = 0;
  }
  cout << best << endl;

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

