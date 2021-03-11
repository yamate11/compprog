#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug binsearch rerror)
// --> f:<< debug binsearch rerror
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
// ---- inserted library file rerror.cc

#if RERROR_LONGDOUBLE
using Real = long double;
#else
using Real = double;
#endif

// Default Error Value.
Real g_err = 1e-9;    // Too small value is not good.

bool r_eq(Real x, Real y, Real err = g_err) {
  return abs(x - y) <= err || abs(x - y) <= abs(x) * err;
}
bool r_le(Real x, Real y, Real err = g_err) {
  return x - y <= err || x - y <= abs(x) * err;
}
bool r_ge(Real x, Real y, Real err = g_err) { return r_le(y, x, err); }
bool r_gt(Real x, Real y, Real err = g_err) { return !r_le(x, y, err); }
bool r_lt(Real x, Real y, Real err = g_err) { return !r_le(y, x, err); }
bool r_ne(Real x, Real y, Real err = g_err) { return !r_eq(x, y, err); }

bool rp_eq(Real x, Real y, Real err = g_err) { return abs(x - y) <= err; }
bool rp_le(Real x, Real y, Real err = g_err) { return x - y <= err; }
bool rp_ge(Real x, Real y, Real err = g_err) { return rp_le(y, x, err); }
bool rp_gt(Real x, Real y, Real err = g_err) { return !rp_le(x, y, err); }
bool rp_lt(Real x, Real y, Real err = g_err) { return !rp_le(y, x, err); }
bool rp_ne(Real x, Real y, Real err = g_err) { return !rp_eq(x, y, err); }

// ---- end rerror.cc
// @@ !! LIM  -- end mark --

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll big = 1e10;

  ll N; cin >> N;
  vector<ll> X(N), Y(N);
  vector<ll> DX(N), DY(N);
  for (ll i = 0; i < N; i++) {
    char c;
    cin >> X.at(i) >> Y.at(i) >> c;
    if (c == 'L') DX.at(i) = -1;
    if (c == 'R') DX.at(i) =  1;
    if (c == 'D') DY.at(i) = -1;
    if (c == 'U') DY.at(i) =  1;
  }
  auto fxH = [&](double t) -> double {
    double res = -big;
    for (ll i = 0; i < N; i++) {
      res = max(res, X.at(i) + DX.at(i) * t);
    }
    return res;
  };
  auto fyH = [&](double t) -> double {
    double res = -big;
    for (ll i = 0; i < N; i++) {
      res = max(res, Y.at(i) + DY.at(i) * t);
    }
    return res;
  };
  auto fxL = [&](double t) -> double {
    double res = big;
    for (ll i = 0; i < N; i++) {
      res = min(res, X.at(i) + DX.at(i) * t);
    }
    return res;
  };
  auto fyL = [&](double t) -> double {
    double res = big;
    for (ll i = 0; i < N; i++) {
      res = min(res, Y.at(i) + DY.at(i) * t);
    }
    return res;
  };
  vector<double> ev;
  ev.push_back(0.0);
  auto mysearch = [&](const auto& f, double bnd) -> void {
    ll t_int = 0;
    double t = t_int / 2.0;
    while (true) {
      double r = (f(t + 0.1) - f(t)) / 0.1;
      if (r_eq(r, bnd)) return;
      auto check = [&](ll tt_int) -> bool {
	double tt = tt_int / 2.0;
	double rr = (f(tt + 0.1) - f(tt)) / 0.1;
	return !r_eq(r, rr);
      };
      t_int = binsearch(check, big, t_int);
      if (t_int == big) return;
      t = t_int / 2.0;
      ev.push_back(t);
      // DLOG("mysearch push.  t=", t, "r=", r);
    }
  };
  mysearch(fxH, 1.0);
  mysearch(fyH, 1.0);
  mysearch(fxL, -1.0);
  mysearch(fyL, -1.0);
  DLOG("ev=", ev);

  double ans = double(big) * big;
  for (double t : ev) {
    double v = (fxH(t) - fxL(t)) * (fyH(t) - fyL(t));
    ans = min(ans, v);
  }
  cout << ans << endl;

  return 0;
}

