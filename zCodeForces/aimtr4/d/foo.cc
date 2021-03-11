#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

struct A {
  virtual void foo() { cout << "I'm in A" << endl; }
};

struct B : A {
  void foo() { cout << "I'm in B" << endl; }
};
  

  void bar(A& a) {
    a.foo();
  }

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  A a;
  B b;
  bar(a);
  bar(b);

  return 0;
}

