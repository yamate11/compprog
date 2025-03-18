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

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<vector<double>> cb(N+1, vector<double>(N+1));
  cb.at(0).at(0) = 1.0;
  for (ll i = 1; i <= N; i++) {
    cb.at(i).at(0) = cb.at(i).at(i) = 1;
    for (ll j = 1; j < i; j++) {
      cb.at(i).at(j) = cb.at(i-1).at(j-1) + cb.at(i-1).at(j);
    }
  }
  DLOG("cb=", cb);
  vector<double> exp(N+1);
  exp.at(1) = 0.0;
  for (ll n = 2; n <= N; n++) {
    DLOG("n=", n);
    double ntot = pow(3.0, n);
    double pself = 0.0;
    double acc = 0.0;
    for (ll h1 = 0; h1 <= n / 3; h1++) {
      for (ll h2 = h1; h2 <= (n - h1) / 2; h2++) {
	ll h3 = n - (h1 + h2);
	DLOG("h=", h1, h2, h3);
	if (h1 == 0) {
	  if (h2 == 0) {
	    pself += 3.0 / ntot;
	    DLOG("pself += ", 3.0 / ntot);
	  }else if (h2 == h3) {
	    double p = 3.0 * cb.at(n).at(h2) / ntot;
	    acc += p * exp.at(h2);
	    DLOG("p=", p, "h2=", h2);
	  }else {
	    double p = 6.0 * cb.at(n).at(h2) / ntot;
	    acc += p * exp.at(h2);
	    DLOG("p=", p, "h2=", h2);
	  }
	}else if (h1 == h2 && h2 == h3) {
	  double p = cb.at(n).at(h1) * cb.at(n-h1).at(h2) / ntot;
	  pself += p;
	  DLOG("pself += ", p);
	}else if (h1 == h2 || h2 == h3) {
	  double p = 3.0 * cb.at(n).at(h1) * cb.at(n-h1).at(h2) / ntot;
	  acc += p * exp.at(h1);
	  DLOG("p=", p, "h1=", h1);
	}else {
	  double p = 6.0 * cb.at(n).at(h1) * cb.at(n-h1).at(h2) / ntot;
	  acc += p * exp.at(h1);
	  DLOG("p=", p, "h1=", h1);
	}
      }
    }
    exp.at(n) = (1.0 + acc) / (1.0 - pself);
    DLOG("exp.at(n)=", exp.at(n));
  }
  cout << exp.at(N) << endl;

  return 0;
}

