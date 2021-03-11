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

  ll H, W; cin >> H >> W;
  using block_t = tuple<ll, ll, ll>;
  ll pAdv = W + 1;
  ll oAdv = W + 1;
  ll pSp = 0;
  ll oSp = 0;
  vector<block_t> block;
  for (ll i = 0; i < H; i++) {
    string S; cin >> S;
    vector<char> pc;
    vector<ll> sp;
    ll prev = -1;
    for (ll j = 0; j < W; j++) {
      if (S.at(j) == '.') continue;
      sp.push_back(j - prev - 1);
      prev = j;
      pc.push_back(S.at(j));
    }
    sp.push_back(W - 1 - prev);
    ll jN = pc.size();
    if (jN == 0) continue;

    ll jSt = 0;
    if (pc.at(0) == 'x') {
      oAdv = min(oAdv, sp.at(0));
      for ( ; jSt < jN && pc.at(jSt) == 'x'; jSt++);
    }
    ll jEn = jN;
    if (pc.at(jEn - 1) == 'o') {
      pAdv = min(pAdv, sp.at(jN));
      for ( ; jEn-1 >= 0 && pc.at(jEn-1) == 'o'; jEn--);
    }
    for (ll jL = jSt; jL < jEn; ) {
      ll jM = jL + 1;
      for ( ; pc.at(jM) == 'o'; jM++);
      ll jR = jM + 1;
      for ( ; jR < jEn && pc.at(jR) == 'x'; jR++);
      for (ll j = jL; j+1 < jM; j++) pSp += (j+1 - jL)   * sp.at(j+1);
      for (ll j = jM; j+1 < jR; j++) oSp += (jR - (j+1)) * sp.at(j+1);
      block.emplace_back(sp.at(jM), jM - jL - 1, jR - jM - 1);
      jL = jR;
    }
  }
  if (pAdv <= W || oAdv <= W) {
    cout << (pAdv <= oAdv ? "o" : "x") << endl;
    return 0;
  }
  sort(block.begin(), block.end(),
       [](const block_t& x, const block_t& y) -> bool {
	 return get<1>(x) + get<2>(x) > get<1>(y) + get<2>(y);
       });
  DLOG("block", block);
  bool rev = false;
  for (const block_t& bl : block) {
    ll gap = get<0>(bl);
    ll pRed = 0;
    ll oRed = 0;
    if (gap % 2 == 0) {
      (rev ? pRed : oRed) = 1;
      rev = !rev;
    }
    pSp += ((gap / 2) - pRed) * get<1>(bl);
    oSp += ((gap / 2) - oRed) * get<2>(bl);
  }
  DLOG("pSp", pSp, "oSp", oSp, "rev", rev);
  cout << (pSp > oSp ? "o" : pSp < oSp ? "x" : rev ? "o" : "x") << endl;

  return 0;
}

