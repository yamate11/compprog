#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  Dijkstra

  Usage:

    ll N = ...; // number of nodes
    auto numNbr = [&](ll x) -> ll { ... };
      // Returns the number of neighbours of node x
    auto fNbr = [&](ll x, ll j) -> ll { ... };
      // Then dist(x,j) returns the j-th neighbour of node x.
    auto dist = [&](ll x, ll j) -> T { ... };
      // dist(x,j) returns distance from x to its j-th neighbour.
    ll orig = ...; // the origin

    Dijkstra<T> dij(N, numNbr, fNbr, dist, orig);    
      // T is usually ll or double.
      // orig is defaulted to 0.

  Results:
    bool reachable(int i);
      // node i is reachable from origin.
    T dist(int i);
      // shortest path-distance from orig to i
      // If unreachable, return value is undefined.
    vector<int> path(int i);
      // shortest path (a vector<int>) from orig to i
      // If unreachable, return value is undefined.

  In particular, if neighbourhood relation is given by 
  vector<vector<pair<ll, T>> nbr, then the following works:

    Dijkstra<T> dij(nbr, orig);

  They are equivallent to:
    auto numNbr = [&](ll i) -> ll { return nbr.at(i).size(); }
    auto dist = [&](ll i, ll j) -> pair<ll, T>  { return nbr.at(i).at(j); }
    Dijkstra<T> dij(nbr.size(), numNbr, dist, orig);


  DijkstraM
    
    Unlike Dikstra, DikstraM supports types other than int/ll for
    nodes, as long as they can be stored in maps.  The DikstraM
    struct is essentially a proxy to Dikstra.  Encoding and Decoding
    functions are needed, but default encoding/deconding are prepared.

    Thus, if you are not very keen about speed, it is OK to write
      auto numNbr = [&](S x) -> ll { ... };
      auto fNbr = [&](S x, ll j) -> S { ... };
      auto dist = [&](S x, ll j) -> T { ... };   
      S orig = ...;
      Dijkstra<T, S> dij(N, numNbr, fNbr, dist, orig);

    You may want to provide your own encoding/decoding functions.
    In that case, you should write class/struct with methods 
    enc(), dec(), and constructor with n and orig, such as:
      struct MyEncDec {
        ll enc(S s) { ... }
        S dec(ll x) { ... }
        MyEncDec(ll n, S orig) { ... }
      };
    and this type should be specified as a template parameter:
      Dikstra<T, S, MyEncDec> dij(N, numNbr, fNbr, dist, orig);

 */


// @@ !! LIM()


//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN()  ---- dijkstra.cc

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


// @@ !! END ---- dijkstra.cc

using Point = pair<ll, ll>;

struct EncDec4 {
  int enc(Point p) { return 5*p.first + p.second; }
  Point dec(int x) { return {x/5, x%5}; }
  EncDec4(int n, Point orig) {}
};
  

int main() {
  vector<vector<pair<ll, ll>>> nbr
    {{{2,1}},                // 0
     {{0,1}, {2,4}, {4,4}},  // 1
     {{1,1}, {3,3}},         // 2
     {{4,3}},                // 3
     {{1,1}, {3,2}},         // 4
     {{4,100}}               // 5
    };
  auto numNbr = [&](ll i) -> ll { return nbr.at(i).size(); };
  auto fNbr = [&](ll i, ll j) -> ll { return nbr.at(i).at(j).first; };
  auto dist = [&](ll i, ll j) -> ll { return nbr.at(i).at(j).second; };
  Dijkstra<ll> dij(6, numNbr, fNbr, dist, 1);

  assert(dij.dist(0) == 1);
  assert(dij.dist(1) == 0);
  assert(dij.dist(2) == 2);
  assert(dij.dist(3) == 5);
  assert(dij.dist(4) == 4);
  assert(! dij.reachable(5));
  assert(dij.path(0) == vector<int>({1,0}));
  assert(dij.path(1) == vector<int>({1}));
  assert(dij.path(2) == vector<int>({1,0,2}));
  assert(dij.path(3) == vector<int>({1,0,2,3}));
  assert(dij.path(4) == vector<int>({1,4}));

  Dijkstra<ll> dij2(nbr);
  assert(dij2.dist(0) == 0);
  assert(dij2.dist(1) == 2);
  assert(dij2.dist(2) == 1);
  assert(dij2.dist(3) == 4);
  assert(dij2.dist(4) == 6);
  assert(! dij2.reachable(5));
  assert(dij2.path(0) == vector<int>({0}));
  assert(dij2.path(1) == vector<int>({0,2,1}));
  assert(dij2.path(2) == vector<int>({0,2}));
  assert(dij2.path(3) == vector<int>({0,2,3}));
  assert(dij2.path(4) == vector<int>({0,2,1,4}));

  auto numNbr3 = [&](Point p) -> ll {
    if (p.first == 0 && p.second == 0) return 2;
    if (p.first == 0 && p.second == 4) return 2;
    if (p.first == 2 && p.second == 0) return 2;
    if (p.first == 3 && p.second == 1) return 2;
    if (p.first == 3 && p.second == 3) return 2;
    return 0;
  };
  auto fNbr3 = [&](Point p, ll j) -> Point {
    if (p.first == 0 && p.second == 0 && j == 0) return {2,0};
    if (p.first == 0 && p.second == 0 && j == 1) return {0,4};
    if (p.first == 0 && p.second == 4 && j == 0) return {2,0};
    if (p.first == 0 && p.second == 4 && j == 1) return {0,0};
    if (p.first == 2 && p.second == 0 && j == 0) return {0,0};
    if (p.first == 2 && p.second == 0 && j == 1) return {3,1};
    if (p.first == 3 && p.second == 1 && j == 0) return {3,3};
    if (p.first == 3 && p.second == 1 && j == 1) return {2,0};
    if (p.first == 3 && p.second == 3 && j == 0) return {3,1};
    if (p.first == 3 && p.second == 3 && j == 1) return {0,4};
    assert(0);
  };
  auto dist3 = [&](Point p, ll j) -> double {
    Point q = fNbr3(p, j);
    return hypot(p.first - q.first, p.second - q.second);
  };

  Point orig3({0,0});
  DijkstraM<double, Point> dij3(5, numNbr3, fNbr3, dist3, orig3);
  assert(abs(dij3.dist({0,0}) - 0.0) < 1e-5);
  assert(abs(dij3.dist({0,4}) - 4.0) < 1e-5);
  assert(abs(dij3.dist({3,3}) - 5.414213562373095) < 1e-5);
  assert(dij3.path({0,4}) == vector<Point>({{0,0},{0,4}}));
  assert(dij3.path({3,3}) == vector<Point>({{0,0},{2,0},{3,1},{3,3}}));
  assert(dij3.reachable({3,3}));
  assert(! dij3.reachable({2,2}));
  
  DijkstraM<double, Point, EncDec4> dij4(36, numNbr3, fNbr3, dist3, orig3);
  assert(abs(dij3.dist({0,0}) - 0.0) < 1e-5);
  assert(abs(dij3.dist({0,4}) - 4.0) < 1e-5);
  assert(abs(dij3.dist({3,3}) - 5.414213562373095) < 1e-5);
  assert(dij3.path({0,4}) == vector<Point>({{0,0},{0,4}}));
  assert(dij3.path({3,3}) == vector<Point>({{0,0},{2,0},{3,1},{3,3}}));
  assert(dij3.reachable({3,3}));
  assert(! dij3.reachable({2,2}));
  

  cout << "Test done." << endl;
}
