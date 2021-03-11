#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(binsearch debug)
// --> binsearch f:<< debug
// ---- inserted library file binsearch.cc

template<typename T>
T binsearch(auto check, T yes, T no, T err = (T)1) {
  while (abs(yes - no) > err) {
    T mid = (yes + no) / (T)2;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

// ---- end binsearch.cc
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

template <typename T>
ostream& operator<< (ostream& os, const stack<T>& st) {
  stack<T> tmp(st);
  os << '[';
  bool first = true;
  while (!tmp.empty()) {
    T& t = tmp.top();
    if (first) first = false;
    else os << ", ";
    os << t;
    tmp.pop();
  }
  os << ']';
  return os;
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

ll lim = (ll)1e5 + 1;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll D, L, N; cin >> D >> L >> N;
  vector<ll> C;
  for (ll i = 0 ;i < D; i++) {
    ll c; cin >> c;
    C.push_back(c);
  }
  vector<ll> K, F, T;
  for (ll i = 0; i < N; i++) {
    ll k, f, t; cin >> k >> f >> t; f--;
    K.push_back(k);
    F.push_back(f);
    T.push_back(t);
  }
  
  
  map<ll, vector<ll>> colPos;
  for (ll i = 0; i < D; i++) colPos[C.at(i)].push_back(i);
  vector<ll> ivl(D);
  for (const auto& [c, v] : colPos) {
    ll m = v.size();
    for (ll i = 0; i < m - 1; i++) ivl.at(v.at(i)) = v.at(i+1) - v.at(i);
    ivl.at(v.at(m-1)) = D + v.at(0) - v.at(m-1);
  }
  using Pair = pair<ll, ll>;
  vector nnf(35, vector<Pair>(D));
  for (ll i = 0; i < D; i++) {
    nnf.at(0).at(i) = {(ivl.at(i) - 1) / L, (i + ivl.at(i)) % D};
  }
  for (ll j = 0; j < 34; j++) {
    for (ll i = 0; i < D; i++) {
      auto [m1, k1] = nnf.at(j).at(i);
      auto [m2, k2] = nnf.at(j).at(k1);
      nnf.at(j+1).at(i) = {m1 + m2, k2};
    }
  }

  DLOG("nnf.at(0)", nnf.at(0));
  DLOG("nnf.at(1)", nnf.at(1));
  DLOG("nnf.at(2)", nnf.at(2));
  DLOG("nnf.at(3)", nnf.at(3));

  auto perPerson = [&](ll i) -> ll {
    DLOG("perPerson, i=", i);
    ll f = F.at(i);
    const auto& vp = colPos[K.at(i)];
    ll s = vp.size();
    if (s == 0) return 0;
    auto check = [&](ll j) -> ll { return f <= vp.at(j); };
    ll j = binsearch<ll>(check, s, -1);
    ll g = 0, len = 0;
    if (j == s) {
      g = vp.at(0);
      len = D + g - f;
    }else {
      g = vp.at(j);
      len = g - f;
    }
    ll noFav = (len == 0) ? 0 : 1 + (len - 1) / L;
    ll fav = 0;
    if (fav + noFav >= T.at(i)) return fav;


    for (ll k = 34; k >= 0; k--) {
      DLOG("k=", k);
      auto [m, gg] = nnf.at(k).at(g);
      if (fav + (1LL << k) + noFav + m == T.at(i)) return fav + (1LL << k);
      if (fav + (1LL << k) + noFav + m < T.at(i)) {
	fav += (1LL << k);
	noFav += m;
	g = gg;
      }
      DLOG("fav=", fav, "noFav=", noFav, "g=", g);
    }
    return fav + 1;
  };

  for (ll i = 0; i < N; i++) cout << perPerson(i) << "\n";

  
  return 0;
}

