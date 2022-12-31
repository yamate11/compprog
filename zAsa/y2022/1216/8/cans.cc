#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

struct A {
  int i;
  A(int i_ = 0) : i(i_) {
    cerr << "A(" << i_ << ")" << endl;
  }
};


void f1(const A& a) {
}

void f2(A& a) {
}

void f3(A&& a) {
  
}


template<typename T>
void f4(T&& a) {
  g1(forward<T>(a));
}

void g1(A&& a) {
  cout << "g1 &&" << endl;
}

void g1(const A& a) {
  cout << "g1 const &" << endl;
}


int main(/* int argc, char *argv[] */) {
  A a1(1);
  const A a2(2);

  f1(a1);
  f1(a2);
  f1(A(10));
  f2(a1);
  // f2(a2);    // error: binding reference of type 'A&' to 'const A' discards qualifiers
  // f2(A(10));  // error: cannot bind non-const lvalue reference of type 'A&' to an rvalue of type 'A'
  cerr << "--- f4(a1)" << endl;
  f4(a1);
  cerr << "--- f4(A(10))" << endl;
  f4(A(10));

  return 0;
}

