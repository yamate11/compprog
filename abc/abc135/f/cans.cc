#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:nnDivCeil strSearch debug)
// --> f:nnDivCeil strSearch f:<< debug
// ---- inserted function nnDivCeil from util.cc
// Natural Number Division and Ceiling
ll nnDivCeil(ll x, ll y) {
  return (x + (y - 1)) / y;
}
// ---- end nnDivCeil
// ---- inserted library file strSearch.cc
vector<int> zAlg(string s) {
  int n = s.size();
  vector<int> z(n);
  z.at(0) = n;
  int i = 1;
  int j = 0;
  while (i < n) {
    for ( ; i+j < n && s.at(j) == s.at(i+j); j++) {}
    z.at(i++) = j;
    if (j > 0) {
      for (int k = 1; i < n && z.at(k) < j-1; k++, j--, i++) z.at(i) = z.at(k);
      j--;
    }
  }
  return z;
}

// matches("abab", "xababab") --> [1,3]
vector<int> matches(string p, string s, char sepChar = '\xff') {
  auto v = zAlg(p + string(1, sepChar) + s);
  int n = p.size();
  vector<int> res;
  for (size_t i = 0; i < s.size() - (n-1); i++) {
    if (v.at(n+1 + i) == n) res.push_back(i);
  }
  return res;
}
// ---- end strSearch.cc
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

struct MyException : exception {};

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string s, t; cin >> s >> t;
  ll n = nnDivCeil(t.size() + s.size() - 1, s.size());
  /*
  stringstream ss;
  for (ll i = 0; i < n; i++) ss << s;
  string se = ss.str();
  */
  string se;
  se.reserve(n * s.size() + 10);
  for (ll i = 0; i < n; i++) se += s;
  vector<bool> vmt(s.size());
  // DLOG("t", t, "se", se);
  for (ll i : matches(t, se)) {
    if (i >= (ll)s.size()) break;
    vmt.at(i) = true;
  }
  vector<ll> gr(s.size(), -2);
  auto mark = [&](ll i) -> ll {
    ll i0 = i;
    if (gr.at(i) != -2) return gr.at(i);
    ll acc = 0;
    while (true) {
      gr.at(i) = 0;
      if (!vmt.at(i)) return acc;
      acc++;
      i = (i + t.size()) % s.size();
      if (i == i0) throw MyException();
    }
  };
  ll ans = 0;
  try {
    for (ll i = 0; i < (ll)s.size(); i++) {
      ans = max(ans, mark(i));
    }
    cout << ans << endl;
  }catch(const MyException& e) {
    cout << -1 << endl;
  }

  return 0;
}

