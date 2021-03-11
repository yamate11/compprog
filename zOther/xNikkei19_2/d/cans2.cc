#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

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

// operator<< definitions for some classes

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p) {
  os << "(" << p.first << ", " << p.second << ")";
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


typedef pair<ll,ll> Pair;

bool operator<(const Pair p1, const Pair p2) {
  if (p1.first < p2.first) return true;
  if (p1.first > p2.first) return false;
  return p1.second < p2.second;
}

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<ll> L(M), R(M), C(M);
  for (int i = 0; i < M; i++) {
    cin >> L.at(i) >> R.at(i) >> C.at(i);
  }
  vector<ll> ordL(M);
  iota(ordL.begin(), ordL.end(), 0);
  sort(ordL.begin(), ordL.end(),
       [&](int p, int q) { return L.at(p) < L.at(q); }
       );
  set<Pair> theS;
  theS.emplace(1, 0);
  for (int i = 0; i < M; i++) {
    ll j = ordL.at(i);
    DLOG("entry", L.at(j), R.at(j), C.at(j));
    auto it = theS.lower_bound(make_pair(L.at(j), 0));
    if (it == theS.end()) {
      cout << "-1\n";
      return 0;
    }
    // ll k = it->first;
    ll d = it->second;
    bool xshort = false;
    for (it++; it != theS.end(); ) {
      ll k1 = it->first;
      ll d1 = it->second;
      if (R.at(j) <= k1) {
	if (d + C.at(j) < d1) {
	  DLOG("emplace", R.at(j), d+C.at(j));
	  theS.emplace(R.at(j), d + C.at(j));
	}
	xshort = true;
	break;
      }
      DLOG("if-statement", d, C.at(j), d1);
      if (d + C.at(j) >= d1) {
	it++;
      }else {
	DLOG("remove", it->first, it->second);
	it = theS.erase(it);
      }
    }
    if (!xshort) {
      DLOG("emplace last", R.at(j), d+C.at(j));
      theS.emplace(R.at(j), d + C.at(j));
    }
  }
  auto it = theS.lower_bound(make_pair(N, 0));
  if (it == theS.end()) {
    cout << "-1\n";
    return 0;
  }else {
    cout << it->second << endl;
    return 0;
  }

}

