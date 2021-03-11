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

template <typename T>  // T is typically int, ll, double, etc.
struct Dijkstra {
  int n;
  int orig;
  vector<T> vdist;
  vector<T> prev;

  Dijkstra(int n_, auto numNbr, auto dist, int orig_ = 0)
    : n(n_), orig(orig_), vdist(n, LLONG_MAX), prev(n) { init(numNbr, dist); }

  void init(auto numNbr, auto dist) {
    using Pair = pair<T, int>;
    priority_queue<Pair, vector<Pair>, greater<Pair>> pque;
    vdist.at(orig) = 0;
    prev.at(orig) = orig;
    pque.emplace(0, orig);
    while (!pque.empty()) {
      Pair p = pque.top(); pque.pop();
      T d = p.first;
      int i = p.second;
      if (vdist.at(i) < d) continue;
      assert(vdist.at(i) == d);
      for (int j = 0; j < numNbr(i); j++) {
	auto pd = dist(i, j);
	T newDist = d + pd.second;
	int k = pd.first;
	if (vdist.at(k) <= newDist) continue;
	vdist.at(k) = newDist;
	prev.at(k) = i;
	pque.emplace(newDist, k);
	DLOG("pque.emplace", newDist, k);
      }
    }
  }

  T dist(int i) { return vdist.at(i); }

  vector<int> path(int i) {
    vector<int> ret;
    while (true) {
      ret.push_back(i);
      int j = prev.at(i);
      if (j == i) break;
      i = j;
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }
};



int main() {
  vector<vector<pair<ll, ll>>> nbr
    {{{2,1}},                // 0
     {{0,1}, {2,4}, {4,4}},  // 1
     {{1,1}, {3,3}},         // 2
     {{4,3}},                // 3
     {{1,1}, {3,2}}          // 4
    };
  auto numNbr = [&](ll i) -> ll { return nbr.at(i).size(); };
  auto dist = [&](ll i, ll j) -> pair<ll, ll> {
    return nbr.at(i).at(j);
  };
  Dijkstra<ll> dij(5, numNbr, dist, 1);
  assert(dij.dist(0) == 1);
  assert(dij.dist(1) == 0);
  assert(dij.dist(2) == 2);
  assert(dij.dist(3) == 5);
  assert(dij.dist(4) == 4);
  assert(dij.path(0) == vector<int>({1,0}));
  assert(dij.path(1) == vector<int>({1}));
  assert(dij.path(2) == vector<int>({1,0,2}));
  assert(dij.path(3) == vector<int>({1,0,2,3}));
  assert(dij.path(4) == vector<int>({1,4}));

  cout << "Test done." << endl;
}
