#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

template<typename T>
struct A {
  using ult = T;
  ult y;
};

struct X {
  int x;
};
  
int main() {
  A<X> a;
  a.y.x = 2;
  cout << a.y.x << endl;
  A<int> b;
  b.y = 3;
  cout << b.y << endl;
}

          
