#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

struct A {
  int x;
  int y;
  A() : x(0), y(0) {
    cerr << "no-argument constructor" << endl;
  }
  A(int x_, int y_) : x(x_), y(y_) {
    cerr << "two-argument construtor" << endl;
  }
  /*
  A(A&& a) : x(a.x), y(a.y) {
    cerr << "move constructor" << endl;
  }
  A(const A& a) : x(a.x), y(a.y) {
    cerr << "const copy constructor" << endl;
  }
  */
};

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<A> vec;

  A a(3, 5);
  vec.push_back(move(a));
  a.x = 10;
  cerr << vec[0].x << endl;
  cerr << a.x << endl;


  return 0;
}
