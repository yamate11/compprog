#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

struct A {
  int x;
  int y;
  A(int xx, int yy) : x(xx), y(yy) {}
  // bool operator <(const A& a) const { return y < a.y; }
};

struct CompA {
  bool operator ()(const A& a1, const A& a2) { return a1.y < a2.y; }
};

set<A, CompA> s;

int main() {
  s.emplace(5, 2);
  s.emplace(7, 1);
  s.emplace(1, 9);
  for (auto z : s) {
    cout << z.x << ", " << z.y << "\n";
  }
}
