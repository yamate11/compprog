#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  guessing Polynomial

  Constructs polynomials P_i, with a same degree, from a given vector v
     P_0(t)     = v[t]   if t % m == 0 and t >= T
     P_1(t)     = v[t]   if t % m == 1 and t >= T
     ...
     P_{m-1}(t) = v[t]   if t % m == m-1 and t >= T

  Usage:
    vector<double> v = ....;
    GuessPoly<double> gp(v, 100, 4, 12, 15);
    // This searches polynomials up to degree 4 (incl.), with period
    // up to 12 (incl.).  The first 100 elements in v are ignored.
    // (i.e. some exceptional values in the prefix are allowed.)
    // It judges if the first 15 + deg points after 100
    // are fit in a polynomial for each residue.
    cout << gp.comp(1000) << endl;  // completion

  WARNING: T should be a field; thus int or long long are not suitable.
           Fp and double are all right.
     This warning is printed when you call comp().  You can remove
     the message by specifying GuessPoly<T, 0> instead of GuessPoly<T>.
 */

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

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- guessPoly.cc

struct GPExc : runtime_error {
  GPExc(const string& msg) : runtime_error(msg) {}
};

template<typename T, int verbose = 1>
class GuessPoly {
  vector<T> store;
  int start;
  int dim_;
  int period_;

  void init_check(int dim_max, int period_max, int conf) {
    for (period_ = 1; period_ <= period_max; period_++) {
      int lim = start + period_ * (conf + dim_max);
      if ((int)store.size() < start + lim) {
	throw GPExc("GuessPoly: Not enough size of vector");
      }
      vector<T> w(store.begin() + start, store.begin() + start + lim);
      auto search = [&]() -> int {
	for (int d = 0; true ; d++) {
	  auto achieve = [&]() -> bool {
	    for (int j = 0; j < period_; j++) {
	      for (int l = 0; l < conf - 1; l++) {
		if (w.at(j + period_ * l) != w.at(j + period_ * (l+1))) {
		  return false;
		}
	      }
	    }
	    return true;
	  };
	  if (achieve()) return d;
	  if (d == dim_max) return -1;
	  for (int t = 0; t < period_ * (conf + dim_max - d - 1); t++) {
	    w.at(t) = w.at(t + period_) - w.at(t);
	  }
	}
      };
      dim_ = search();
      if (dim_ >= 0) return;
    }
    throw GPExc("GuessPoly: Failed to find dim and period.");
  }

public:
  GuessPoly(const vector<T>& v, int start_,
	    int dim_max, int period_max, int conf)
    : store(v), start(start_) {
    init_check(dim_max, period_max, conf);
  }

  int dim() { return dim_; }
  int period() { return period_; }

  // completion
  T comp(ll x) {
    if (verbose) {
      cerr << "WARNING: You should use a FIELD for type T.  "
	   << "You can remove this warning by setting verbose=0."
	   << endl;
    }
    if (x < (ll)store.size()) return store.at(x);
    ll r = (x - start) % period_;
    ll q = (x - start) / period_;
    T ans = 0;
    for (int i = 0; i < dim_ + 1; i++) {
      T y = store.at(start + r + i * period_);
      for (int j = 0; j < dim_ + 1; j++) {
	if (j == i) continue;
	y *= T(q - j) / T(i - j);
      }
      ans += y;
    }
    return ans;
  }
};



// @@ !! END ---- guessPoly.cc


int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto f = [](ll i, ll j) -> ll {
    return (2 + j) * i*i + (5 - j) * i + 4 * j;
  };
  vector<double> v;
  for (ll i = 0; i < 100; i++) {
    for (ll j = 0; j < 3; j++) {
      v.push_back(f(i, j));
    }
  }
  GuessPoly<double, 0> gp(v, 0, 2, 3, 10);
  assert(gp.comp(600) == f(200, 0));
  assert(gp.comp(601) == f(200, 1));
  assert(gp.comp(602) == f(200, 2));

  return 0;
}

