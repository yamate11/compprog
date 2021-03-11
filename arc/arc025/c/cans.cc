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

using Pair = pair<ll,ll>;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, R, T; cin >> N >> M >> R >> T;
  bool rev = false;
  if (R < T) {
    rev = true;
    swap(R, T);
  }

  vector<vector<pair<ll,ll>>> nbr(N);
  for (ll i = 0; i < M; i++) {
    ll a, b, c; cin >> a >> b >> c; a--; b--;
    nbr.at(a).emplace_back(b, c);
    nbr.at(b).emplace_back(a, c);
  }
  ll totL = 0;
  ll totE = 0;
  for (ll i = 0; i < N; i++) {
    vector<ll> dist(N, 1e10);
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    pq.emplace(0, i);
    while (!pq.empty()) {
      Pair p = pq.top(); pq.pop();
      ll d = p.first;
      ll j = p.second;
      if (d >= dist.at(j)) continue;
      dist.at(j) = d;
      for (Pair q : nbr.at(j)) {
	ll newD = d + q.second;
	if (newD < dist.at(q.first)) pq.emplace(newD, q.first);
      }
    }
    DLOG("i, dist", i, dist);
    sort(dist.begin(), dist.end());
    ll limL = 0;
    for (ll j = 2; j < N; j++) {
      for ( ; limL+1 < N && dist.at(limL+1) * R < dist.at(j) * T; limL++);
      ll limE = limL;
      for ( ; limE+1 < N && dist.at(limE+1) * R == dist.at(j) * T; limE++);
      totE += limE - limL;
      totL += limL;
    }
  }
  if (rev) {
    cout << N * (N-1) * (N-2) - totE - totL << endl;
  }else {
    cout << totL << endl;
  }

  return 0;
}

