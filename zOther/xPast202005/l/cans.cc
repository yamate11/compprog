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
  vector T(N, deque<ll>());
  for (ll i = 0; i < N; i++) {
    ll k; cin >> k;
    for (ll j = 0; j < k; j++) {
      ll t; cin >> t;
      T.at(i).push_back(t);
    }
  }
  
  using Pair = pair<ll, ll>;
  priority_queue<Pair> pq1, pq2;
  for (ll i = 0; i < N; i++) {
    if (T.at(i).size() >= 1) {
      pq1.emplace(T.at(i).at(0), i);
      pq2.emplace(T.at(i).at(0), i);
    }
    if (T.at(i).size() >= 2) {
      pq2.emplace(T.at(i).at(1), i);
    }
  }

  set<ll> used;
  ll M; cin >> M;
  for (ll _q = 0; _q < M; _q++) {
    DLOG("_q=", _q);
    DLOG("pq1=", pq1);
    DLOG("pq2=", pq2);
    ll a; cin >> a;
    if (a == 1) {
      auto [exp, i] = pq1.top(); pq1.pop();
      cout << exp << "\n";
      T.at(i).pop_front();
      if (T.at(i).size() > 0) {
	pq1.emplace(T.at(i).front(), i);
      }
      if (T.at(i).size() > 1) {
	pq2.emplace(T.at(i).at(1), i);
      }
      used.insert(exp);
    }else {
      auto [exp1, i1] = pq1.top();
      ll exp2 = -1;
      ll i2 = -1;
      while (true) {
	tie(exp2, i2) = pq2.top();
	if (used.find(exp2) == used.end()) break;
	pq2.pop();
      }
      if (exp1 >= exp2) {
	pq1.pop();
	cout << exp1 << "\n";
	T.at(i1).pop_front();
	if (T.at(i1).size() > 0) {
	  pq1.emplace(T.at(i1).front(), i1);
	}
	if (T.at(i1).size() > 1) {
	  pq2.emplace(T.at(i1).at(1), i1);
	}
	used.insert(exp1);
      }else {
	pq2.pop();
	cout << exp2 << "\n";
	ll i2_front = T.at(i2).front();
	T.at(i2).pop_front();
	T.at(i2).pop_front();
	T.at(i2).push_front(i2_front);
	if (T.at(i2).size() > 1) {
	  pq2.emplace(T.at(i2).at(1), i2);
	}
      }
    }
  }
  

  return 0;
}

