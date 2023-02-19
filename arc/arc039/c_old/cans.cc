#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// --- DEBUG begin --- cut here ---
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
// --- DEBUG end --- cut here ---


inline auto nextIter(auto it) {
  auto ret = it;
  ret++;
  return ret;
}

inline auto prevIter(auto it) {
  auto ret = it;
  ret--;
  return ret;
}

using DS = map<ll, map<ll, ll>>;

DS vert, horiz;
void op(DS& mpT, DS& mpO, ll& cT, ll& cO, int dir) {
  map<ll, ll>& sT = mpT[cO];
  auto it = prevIter(sT.upper_bound(cT));
  if (dir > 0) {
    ll rB = it->first;
    cT = it->second + 1;
    auto getEnd = [&]() -> ll {
      auto it2 = nextIter(it);
      if (it2 == sT.end()) return cT;
      if (it2->first != cT + 1) return cT;
      ll ret = it2->second;
      sT.erase(it2);
      return ret;
    };
    sT[rB] = getEnd();
  }else {
    cT = it->first - 1;
    ll rEnd = it->second;
    auto getBegin = [&]() -> ll {
      if (it == sT.begin()) return cT;
      auto it2 = prevIter(it);
      if (it2->second != cT - 1) return cT;
      ll ret = it2->first;
      sT.erase(it2);
      return ret;
    };
    ll rBegin = getBegin();
    sT.erase(it);
    sT[rBegin] = rEnd;
  }
  map<ll, ll>& sO = mpO[cT];
  auto jt1 = sO.lower_bound(cO); 
  auto getVBegin = [&]() -> ll {
    if (jt1 == sO.begin()) return cO;
    auto jt2 = prevIter(jt1);
    if (jt2->second != cO - 1) return cO;
    ll ret = jt2->first;
    sO.erase(jt2);
    return ret;
  };
  ll vBegin = getVBegin();
  auto getVEnd = [&]() -> ll {
    if (jt1 == sO.end()) return cO;
    if (jt1->first != cO + 1) return cO;
    ll ret = jt1->second;
    sO.erase(jt1);
    return ret;
  };
  sO[vBegin] = getVEnd();
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll K; cin >> K;
  string S; cin >> S;
  ll cx = 0, cy = 0;

  horiz[0][0] = 0;
  vert[0][0] = 0;
  for (char z : S) {
    if (z == 'L') op(horiz, vert, cx, cy, -1);
    else if (z == 'R') op(horiz, vert, cx, cy, 1);
    else if (z == 'U') op(vert, horiz, cy, cx, 1);
    else if (z == 'D') op(vert, horiz, cy, cx, -1);
    else assert(0);
    DLOG("* ", z, cx, cy);
    DLOG("** ", horiz);
  }
  cout << cx << " " << cy << endl;
  return 0;
}

