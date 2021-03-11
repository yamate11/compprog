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

using Vec1 = vector<ll>;
using Vec2 = vector<Vec1>;
using Vec3 = vector<Vec2>;

ll R, C, K;
ll bsize;
vector<char> brd;

ll big = 1e9;

ll enc(ll i, ll j) { return (i+1) * (C+2) + j+1; }
pair<ll, ll> dec(ll e) {
    return make_pair(e / (C+2) - 1, e % (C+2) - 1);
}

void handle(const auto& tbl, auto& que, ll k, ll d, ll r, ll c) {
  ll e = enc(r, c);
  if (brd.at(e) == 'T') return;
  ll newK = k + (brd.at(e) == 'E' ? 1 : 0);
  if (newK > K) return;
  if (tbl.at(newK).at(e) > d+1) que.emplace(d+1, newK, e);
}

Vec2 calc(ll from) {
  Vec2 tbl(K+1, Vec1(bsize, big));
  using Tup = tuple<ll, ll, ll>;
  queue<Tup> que;
  que.emplace(0, 0, from);
  while (!que.empty()) {
    Tup t = que.front(); que.pop();
    ll d, k, p; tie(d, k, p) = t;
    if (tbl.at(k).at(p) <= d) continue;
    for (ll kk = k; kk <= K && d < tbl.at(kk).at(p); kk++) {
      tbl.at(kk).at(p) = d;
    }
    auto decoded = dec(p);
    ll y = decoded.first, x = decoded.second;
    for (ll dd = -1; dd <= 1; dd += 2) {
      handle(tbl, que, k, d, y + dd, x);
      handle(tbl, que, k, d, y, x + dd);
    }
  }
  return tbl;
};

Vec2 merge(const Vec2& tbl1, const Vec2& tbl2, ll dbl) {
  Vec2 ret(K + 1, Vec1(bsize, big));
  for (ll r = 0; r < R; r++) {
    for (ll c = 0; c < C; c++) {
      ll e = enc(r, c);
      for (ll k = 0; k <= K; k++) {
	ll val = big;
	ll kS = brd.at(e) == 'E' ? 1 : 0;
	for (ll l = 0; l <= k; l++) {
	  ll m = k - l + kS;
	  if (m > K) continue;
	  val = min(val, tbl1.at(l).at(e) + dbl * tbl2.at(m).at(e));
#if DEBUG	  
	  if (r == 2 && c == 4) {
	    cerr << "tbl1 : " << tbl1.at(l).at(e)
		 << "  tbl2 : " << tbl2.at(m).at(e) << endl;
	    cerr << "k = " << k << " l = " << l << " val = " << val << endl;
	  }
#endif
	}
	ret.at(k).at(e) = val;
      }
    }
  }
  return ret;
};

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  cin >> R >> C >> K;
  bsize = (C+2) * (R+2);
  brd.resize(bsize);
  ll start = -1;
  ll church = -1;
  ll goal = -1;
  for (ll i = 0; i < R; i++) {
    string s; cin >> s;
    for (ll j = 0; j < C; j++) {
      brd.at(enc(i, j)) = s.at(j);
      if (s.at(j) == 'S') start = enc(i, j);
      if (s.at(j) == 'C') church = enc(i, j);
      if (s.at(j) == 'G') goal = enc(i, j);
    }
  }
  for (ll i = -1; i <= R; i++) brd.at(enc(i, -1)) = brd.at(enc(i, C)) = 'T';
  for (ll i = -1; i <= C; i++) brd.at(enc(-1, i)) = brd.at(enc(R, i)) = 'T';
  
  Vec2 tblS = calc(start);
  Vec2 tblC = calc(church);
  Vec2 tblG = calc(goal);
  Vec2 tblSC = merge(tblS, tblC, 2);
  Vec2 tblSCG = merge(tblSC, tblG, 1);
  
  auto showtbl = [&](const auto& tbl) -> void {
    for (ll k = 0; k <= K; k++) {
      DLOG("k = ", k);
      for (ll r = 0; r < R; r++) {
	for (ll c = 0; c < C; c++) {
	  cerr << setw(4) << tblS.at(k).at(enc(r, c));
	}
	cerr << endl;
      }
      cerr << endl;
    }
  };

  DCALL(showtbl, tblS);
  DCALL(showtbl, tblC);
  DCALL(showtbl, tblSCG);
  
  ll ans = big;
  for (ll p = 0; p < bsize; p++) ans = min(ans, tblSCG.at(K).at(p));
  cout << (ans < big ? ans : -1) << endl;

  return 0;
}

