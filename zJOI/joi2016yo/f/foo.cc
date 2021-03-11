#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;



struct X {
  int x;

  const int& foo() const {
    cout << "const version" << endl;
    return x;
  }

  int& foo() {
    cout << "non-const version" << endl;
    return x;
  }

  X() : x(10) {}
};



int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  X a = X();
  const X b = X();
  int& y = a.foo();
  y = 20;
  cout << a.x << endl;
  int z = b.foo();
  cout << b.x << endl;
  cout << z << endl;

}
