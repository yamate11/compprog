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

struct OP1 {
  void subst_add(int& u, const int& v) { u += v; }
  void subst_subt(int& u, const int& v) { u -= v; }
  void subst_mult(int& u, const int& v) { u *= v; }
};

struct OP2 {
  void subst_add(int& u, const int& v) { u += v; }
  void subst_mult(int& u, const int& v) { u *= v; }
};

template<typename OP>
struct A {
  int add(int x, int y) { int z = x;  OP().subst_add(z, y); return z; }
  int subt(int x, int y) { int z = x; OP().subst_subt(z, y); return z; }
  int mult(int x, int y) { int z = x; OP().subst_mult(z, y); return z; }
};

template<typename C>
struct SS1 {
  using t = int;
};

template<typename C>
struct SS2 {
  using t = C;
};

struct C1 {
  double p;
  C1(double p_) : p(p_) {}
};

template<typename SS>
struct B {
  typename SS::t x;
  B() : x(0) {}
};

template<typename A>
using BB = B<SS2<A>>;

int main() {
  A<OP1> a;
  cout << a.add(2, 5) << endl;
  cout << a.subt(3, 4) << endl;
  cout << a.mult(3, 4) << endl;

  // B<SS1<int>> b;
  BB<C1> b;
  b.x = C1(5);
  cout << b.x.p << endl;

}
