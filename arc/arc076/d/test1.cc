#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

struct A {
  int fld1;
  int fld2;
  A() {
    fld1 = 0;
    fld2 = 0;
    cerr << "Default Constructor, " << fld1 << ", " << fld2 << endl;
  }
  A(A& a) {
    fld1 = a.fld1;
    fld2 = a.fld2;
    cerr << "Copy Constructor, " << fld1 << ", " << fld2 << endl;
  }
  A(const A& a) {
    fld1 = a.fld1;
    fld2 = a.fld2;
    cerr << "Copy Constructor, " << fld1 << ", " << fld2 << endl;
  }
  A(int f1, int f2) : fld1(f1), fld2(f2) {
    cerr << "Constructor, " << f1 << ", " << f2 << endl;
  }
  ~A() {
    cerr << "Destructor, " << fld1 << ", " << fld2 << endl;
  }
};


vector<A> va;
unordered_map<int, A> mp;

void foo() {
  cerr << "start of foo\n";
  A a(3, 4);
  cerr << "before emplace\n";
  mp[10] = a;
  // mp.emplace(10, a);
  // va.emplace_back(5, 6);
  cerr << "end of foo\n";
}

int main() {
  cerr << "start of main\n";
  foo();
  cerr << "end of main\n";
}
