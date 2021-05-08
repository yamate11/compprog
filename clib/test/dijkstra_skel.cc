#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(dijkstra)


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
