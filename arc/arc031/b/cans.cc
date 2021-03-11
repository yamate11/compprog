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

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<vector<bool>> brd(10, vector<bool>(10));
  ll initI = -1, initJ = -1;
  ll numT = 0;
  for (ll i = 0; i < 10; i++) {
    string s; cin >> s;
    for (ll j = 0; j < 10; j++) {
      if (s.at(j) == 'o') {
	if (initI < 0) {
	  initI = i;
	  initJ = j;
	}
	brd.at(i).at(j) = true;
	numT++;
      }
    }
  }
  DLOG("numT", numT);
  
  auto chkConn = [&](vector<vector<bool>> tb) -> bool {
    vector<vector<bool>> visited(10, vector<bool>(10));
    ll cnt = 0;
    auto dfs = [&](const auto& recF, int i, int j) -> void {
      if (i < 0 || i >= 10 || j < 0 || j >= 10) return;
      if (!tb.at(i).at(j)) return;
      if (visited.at(i).at(j)) return;
      visited.at(i).at(j) = true;
      cnt++;
      recF(recF, i-1, j);
      recF(recF, i+1, j);
      recF(recF, i, j-1);
      recF(recF, i, j+1);
    };
    dfs(dfs, initI, initJ);
    DLOG("cnt", cnt);
    return cnt == numT + 1;
  };

  for (ll i = 0; i < 10; i++) {
    for (ll j = 0; j < 10; j++) {
      if (brd.at(i).at(j)) continue;
      vector<vector<bool>> tmpBrd(brd);
      tmpBrd.at(i).at(j) = true;
      DLOG("i, j", i, j);
      if (chkConn(tmpBrd)) {
	cout << "YES\n";
	return 0;
      }
    }
  }
  cout << "NO\n";
  return 0;
}

