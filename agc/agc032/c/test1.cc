#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class A {
public:
  int size() { return 1; }
  ll at(int i) { return 3; }
};

void func1(auto ps) {
  for (ll i = 0; i < (ll) ps.size(); i++) {
    printf("%lld\n", ps.at(i));
  }
}

int main() {
  vector<ll> xs = {1,2,3};
  func1(xs);
  A y;
  func1(y);
  return 0;
}
