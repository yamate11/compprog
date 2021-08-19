#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace::std;

struct A {
  /*
  A(const A& a) {}
  A(A&& a) {}
  */
};

/*
void func(A a) {
  cout << "func(A)" << endl;
}
*/

void func(const A& a) {
  cout << "func(const A&)" << endl;
}

void func(A&& a) {
  cout << "func(A&&)" << endl;
}

int main() {

  A a1;
  A a2;
  func(a1);
  func(move(a2));

  return 0;
}


  
