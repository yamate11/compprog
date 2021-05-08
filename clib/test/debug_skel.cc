#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug)

int main() {
  cout << setprecision(20);
  
  string s1("hello");
  string s2("world");

  DLOG(10, 1LL << 40, 1 << 15);

  ll x = 1LL << 50;
  DFMT("x = %lld", x);

  auto func1 = [&x](int d) {
    for (int i = 0; i < 1LL << 28; i++) x += d;
  };
  DCALL(func1, 1);
  
  return 0;

}

