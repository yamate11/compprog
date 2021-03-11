#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

struct A {
  int x;
  int y;
  A(int xx, int yy) : x(xx), y(yy) {}
  string toStr() {
    return to_string(x) + ":" + to_string(y);
  }
};


int main() {
  map<int, A> mp;

  A a1(3, 4);
  mp.emplace(100, a1);
  A a2(5, 6);
  mp.emplace(200, a2);
  A a3(0, 0);
  for (auto& t : mp) {
    t.second = a3;
  }
  for (auto t : mp) {
    cout << t.first << ", " << t.second.toStr() << endl;
  }
}
