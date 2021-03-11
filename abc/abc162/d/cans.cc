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

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; string S; cin >> N >> S;
  
  vector<char> cc(3);
  cc.at(0) = 'R'; cc.at(1) = 'G'; cc.at(2) = 'B';
  map<char, ll> rr;
  rr['R'] = 0;
  rr['G'] = 1;
  rr['B'] = 2;

  vector<vector<ll>> pp(3, vector<ll>(N+1));
  for (ll i = 0; i < N; i++) {
    for (ll c = 0; c < 3; c++) {
      if (S.at(i) == cc.at(c)) pp.at(c).at(i+1) = pp.at(c).at(i) + 1;
      else                     pp.at(c).at(i+1) = pp.at(c).at(i) + 0;
    }
  }
  ll cnt = 0;

  for (ll i = 1; i < N-1; i++) {
    ll ci = rr[S.at(i)];
    DLOG("**** i=", i, "ci=", ci);
    for (ll c = 0; c < 3; c++) {
      if (c == ci) continue;
      ll d = 0;
      for (; d == c || d == ci; d++);
      ll x = pp.at(c).at(i) * (pp.at(d).at(N) - pp.at(d).at(i+1));
      cnt += x;
      DLOG("c=", c, "d=", d, "x=", x, "cnt=", cnt);
    }
    for (ll k = 0; k < i; k++) {
      ll z = 2*i - k;
      if (z == k || z < 0 || z >= N) continue;
      if (S.at(k) != S.at(z) && S.at(k) != S.at(i) && S.at(z) != S.at(i)) {
	DLOG("cnt dec", "k=", k, "z=", z);
	cnt--;
      }
    }
  }
  cout << cnt << endl;


  return 0;
}

