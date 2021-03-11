#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

auto makePred(ll x) {
  return [&](ll q) -> bool { return q >= x; };
}

template <typename T>
struct Foo {
  Foo() {}
  void m1(T pred) { cout << (pred(10) ? "True" : "False") << endl; }
};
  


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto pred = makePred(5);
  auto pred2 = makePred(15);
  Foo<decltype(pred)> foo;
  foo.m1(pred);
  foo.m1(pred2);
}
