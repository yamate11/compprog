#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

struct A {
  int x;
  int y;
  // A() : x(0), y(0) {}
  A(int xx, int yy) : x(xx), y(yy) {}
};

deque<A> da;

int main() {
  da.emplace_back(5, 3);
  A a = da.front();
  a.x = 500;
  cout << a.x << endl;
  cout << da.front().x << endl;
  A& a2(da.front());
  da.pop_front();
  if (a2.x == 200) {
    a2.x = 300;
  }
  cout << a2.x << endl;
  // cout << da.front().x << endl;
  
  

}
