#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug dijkstra)
// --> f:<< debug dijkstra
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
// ---- inserted library file dijkstra.cc

template <typename T>
struct Dijkstra {
  int n;
  int orig;
  vector<T> vdist;
  vector<bool> used;  // CAUTION: vdist.at(x) is only meaningful when
                      //          used.at(x) is true.
  vector<T> prev;

  Dijkstra(int n_, auto numNbr, auto fNbr, auto dist, int orig_ = 0)
    : n(n_), orig(orig_) { init(numNbr, fNbr, dist); }

  Dijkstra(vector<vector<pair<ll, T>>> nbr, int orig_ = 0)
    : n(nbr.size()), orig(orig_) { init2(nbr); }

  Dijkstra(vector<vector<pair<int, T>>> nbr, int orig_ = 0)
    : n(nbr.size()), orig(orig_) { init2(nbr); }

  void init2(auto nbr) {
    init([&](int x) -> int { return nbr.at(x).size(); },
	 [&](int x, int j) -> int { return nbr.at(x).at(j).first; },
	 [&](int x, int j) -> T { return nbr.at(x).at(j).second; });
  };

  void init(auto numNbr, auto fNbr, auto dist) {
    using Pair = pair<T, int>;
    vdist.resize(n);
    used.resize(n);
    prev.resize(n);
    priority_queue<Pair, vector<Pair>, greater<Pair>> pque;
    vdist.at(orig) = 0;
    used.at(orig) = true;
    prev.at(orig) = orig;
    pque.emplace(0, orig);
    while (!pque.empty()) {
      Pair p = pque.top(); pque.pop();
      T d = p.first;
      int x = p.second;
      // DLOG("popped up from pque", d, x, vdist.at(x));
      assert(used.at(x));
      if (vdist.at(x) < d) continue;
      assert(vdist.at(x) == d);
      for (int j = 0; j < numNbr(x); j++) {
	T newDist = d + dist(x, j);
	int y = fNbr(x, j);
	// DLOG("internal", "x", x, "j", j, "y", y,
	//      "dist", dist(x, j), "newDist", newDist);
	if (used.at(y) && vdist.at(y) <= newDist) continue;
	vdist.at(y) = newDist;
	used.at(y) = true;
	prev.at(y) = x;
	pque.emplace(newDist, y);
	// DLOG("emplace newdist", newDist, y);
      }
    }
  }

  bool reachable(int x) {
    return 0 <= x && x < (int)used.size() && used.at(x);
  }

  // If x is unreachable, result is undefined.
  T dist(int x) { return vdist.at(x); }

  // If x is unreachable, result is undefined.
  vector<int> path(int i) {
    vector<int> ret;
    while (true) {
      ret.push_back(i);
      int j = prev.at(i);
      if (j == i) break;
      i = j;
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }
};


template <typename S>
struct DefEncDec {
  map<S, int> mp_enc;
  vector<S> v_dec;

  int enc(S s) {
    auto it = mp_enc.find(s);
    if (it != mp_enc.end()) return it->second;
    else {
      int t = v_dec.size();
      mp_enc[s] = t;
      v_dec.push_back(s);
      return t;
    }
  }

  S dec(int x) { return v_dec.at(x); }

  DefEncDec(int n, S orig) : mp_enc({{orig,0}}), v_dec({orig}) {}
};


template <typename T, typename S, typename EncDec = DefEncDec<S>>
struct DijkstraM {
  EncDec ed;
  Dijkstra<T> body;

  DijkstraM(int n, auto numNbr, auto fNbr, auto dist, S orig) :
    ed(n, orig),
    body(n,
	 [&](int x) -> int { return numNbr(ed.dec(x)); },
	 [&](int x, int j) -> int { return ed.enc(fNbr(ed.dec(x), j)); },
	 [&](int x, int j) -> T { return dist(ed.dec(x), j); },
	 ed.enc(orig))
  {}
  
  bool reachable(S s) { return body.reachable(ed.enc(s)); }

  // If s is unreachable, the result is undefined.
  T dist(S s) { return body.dist(ed.enc(s)); }

  // If s is unreachable, the result is undefined.
  vector<S> path(S s) {
    vector<S> ret;
    for (int x : body.path(ed.enc(s))) ret.push_back(ed.dec(x));
    return ret;
  }
};


// ---- end dijkstra.cc
// @@ !! LIM  -- end mark --

/*
  NOTE: To solve this problem, BFS is sufficient and Dijkstra is an overkill.
  Here, we try Dijkstra for verifying the library.
 */

using Pair = pair<ll, ll>;

struct MyED {
  int enc(Pair p) { return p.first * 3 + p.second; }
  Pair dec(int x) { return {x/3, x%3}; }
  MyED(int n, Pair orig) {}
};

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<vector<ll>> nbr(N);
  for (ll i = 0; i < M; i++) {
    ll u, v; cin >> u >> v; u--; v--;
    nbr.at(u).push_back(v);
  }
  ll S, T; cin >> S >> T; S--, T--;

  auto numNbr = [&](Pair x) -> ll {
    return nbr.at(x.first).size();
  };
  auto fNbr = [&](Pair x, ll j) -> Pair {
    return {nbr.at(x.first).at(j), (x.second + 1) % 3};
  };
  auto dist = [&](Pair x, ll j) -> ll {
    return 1;
  };
  DijkstraM<ll, Pair, MyED> dij(N*3, numNbr, fNbr, dist, {S,0});

  DLOG("(5,1)", dij.reachable({5,1}));
  DLOG("(1,2)", dij.reachable({1,2}));
  DLOG("(2,0)", dij.reachable({2,0}));
  DLOG("(3,1)", dij.reachable({3,1}));
  DLOG("(4,2)", dij.reachable({4,2}));
  DLOG("(6,0)", dij.reachable({6,0}));

  if (dij.reachable({T,0})) {
    cout << (dij.path({T,0}).size() - 1) / 3 << endl;
  }else {
    cout << -1 << endl;
  }

  return 0;
}

