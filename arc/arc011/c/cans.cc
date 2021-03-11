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

  string sf, sl; cin >> sf >> sl;
  ll N; cin >> N;
  vector<string> S;
  S.push_back(sf);
  S.push_back(sl);
  for (ll i = 0; i < N; i++) {
    string s; cin >> s;
    S.push_back(s);
  }
  if (sf == sl) {
    cout << 0 << endl << sf << endl << sl << endl;
    return 0;
  }
  ll len = sf.size();
  vector<vector<ll>> nbr(N+2);
  for (ll i = 0; i < N+2; i++) {
    for (ll j = i+1; j < N+2; j++) {
      ll cnt = 0;
      for (ll k = 0; k < len; k++) {
	if (S.at(i).at(k) != S.at(j).at(k)) cnt++;
	if (cnt >= 2) break;
      }
      if (cnt == 1) {
	nbr.at(i).push_back(j);
	nbr.at(j).push_back(i);
      }
    }
  }
  DLOG("nbr", nbr);
  vector<ll> prev(N+2, -1);
  using Tup = tuple<ll, ll, ll>;  // dist, this_node, prev_node
  queue<Tup> que;
  que.emplace(0, 0, 0);
  ll dist, thisN, prevN; 
  while (!que.empty()) {
    auto t = que.front(); que.pop();
    tie(dist, thisN, prevN) = t;
    if (prev.at(thisN) >= 0) continue;
    prev.at(thisN) = prevN;
    if (thisN == 1) break;
    for (ll k : nbr.at(thisN)) {
      if (prev.at(k) >= 0) continue;
      que.emplace(dist + 1, k, thisN);
    }
  }
  if (prev.at(1) < 0) {
    cout << -1 << endl;
    return 0;
  }
  cout << dist-1 << endl;
  vector<ll> seq;
  for (ll c = 1; true; c = prev.at(c)) {
    seq.push_back(c);
    if (c == 0) break;
  }
  for (ll i = seq.size() - 1; i >= 0; i--) cout << S.at(seq.at(i)) << "\n";
  return 0;
}

