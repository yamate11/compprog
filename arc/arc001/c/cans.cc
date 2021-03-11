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

bool solve(auto& pos) {
  DLOG("solve");
  vector<bool> x(8), y(8), diag1(15), diag2(15);
  for (ll i = 0; i < 8; i++) {
    DLOG("i", i);
    string S; cin >> S;
    for (ll j = 0; j < 8; j++) {
      DLOG("j", j);
      if (S.at(j) == '.') continue;
      if (y.at(i) || x.at(j) || diag1.at(i+j) || diag2.at(i-j+7)) return false;
      pos.at(i).at(j) = true;
      y.at(i) = x.at(j) = diag1.at(i+j) = diag2.at(i-j+7) = true;
    }
  }
  DLOG("phase1");
  auto chk_y = [&](const auto& recF, ll i) -> bool {
    DLOG("chk_y", i);
    auto chk_x = [&](ll j) -> bool {
      DLOG("chk_x", i, j, diag1);
      if (x.at(j) || diag1.at(i+j) || diag2.at(i-j+7)) return false;
      pos.at(i).at(j) = true;
      x.at(j) = diag1.at(i+j) = diag2.at(i-j+7) = true;
      if (recF(recF, i+1)) return true;
      pos.at(i).at(j) = false;
      x.at(j) = diag1.at(i+j) = diag2.at(i-j+7) = false;
      return false;
    };
    if (i == 8) return true;
    if (y.at(i)) return recF(recF, i+1);
    for (ll j = 0; j < 8; j++) if (chk_x(j)) return true;
    return false;
  };
  return chk_y(chk_y, 0);
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  vector<vector<bool>> pos(8, vector<bool>(8));
  if (solve(pos)) {
    for (ll i = 0; i < 8; i++) {
      for (ll j = 0; j < 8; j++) {
	cout << (pos.at(i).at(j) ? 'Q' : '.');
      }
      cout << endl;
    }
  }else {
    cout << "No Answer\n";
  }

  return 0;
}

