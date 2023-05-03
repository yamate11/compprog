#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


void func1() {
  using T = double;
  T x = (T)1 / 3;
  cout << x << endl;
}

void func2() {
  using T = string;
  T x = "foo";
  cout << x << endl;
}


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  func1();
  func2();

}
