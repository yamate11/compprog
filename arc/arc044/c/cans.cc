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

ll big = 1e12;
ll tlim = 1e5;
// ll tlim = 1;

ll solve(ll L, vector<ll> T, vector<ll> X) {
  ll N = T.size();
  vector<ll> panel(L+2);
  panel.at(0) = panel.at(L+1) = big;
  vector<vector<ll>> xx(tlim+1);
  for (ll i = 0; i < N; i++) xx.at(T.at(i)).push_back(X.at(i));
  for (ll t = tlim; t >= 1; t--) {
    auto dan = xx.at(t);
    sort(dan.begin(), dan.end());
    DLOG("dan", dan);
    ll dsize = dan.size();
    for (ll i = 0; i < dsize; ) {
      ll r = 1;
      for ( ; i+r < dsize && dan.at(i+r-1) + 1 == dan.at(i+r); r++);
      ll xb = panel.at(dan.at(i) - 1);
      ll xe = panel.at(dan.at(i) + r);
      for (ll j = 0; j < r; j++) {
	panel.at(dan.at(i) + j) = min( j+1 + xb, (r-j) + xe);
      }
      i += r;
    }
  }
  ll ret = LLONG_MAX;
  for (ll i = 1; i <= L; i++) ret = min(ret, panel.at(i));
  DLOG("ret", ret);
  return ret;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll W, H, Q; cin >> W >> H >> Q;
  vector<ll> T0, X0, T1, X1;
  for (ll i = 0; i < Q; i++) {
    ll t, d, x; cin >> t >> d >> x;
    if (d == 0) {
      T0.push_back(t);
      X0.push_back(x);
    }else {
      T1.push_back(t);
      X1.push_back(x);
    }
  }
  ll a = solve(W, T0, X0) + solve(H, T1, X1);
  cout << (a >= big ? -1 : a)  << endl;

  return 0;
}

