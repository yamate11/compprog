#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

template<typename T>
struct Foo {
  vector<T> body;

  Foo(vector<T> b) : body(b) {}
  typename vector<T>::reference at(int i) { return body[i]; }
  typename vector<T>::const_reference at(int i) const { return body[i]; }
};


int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<bool> a({1, 0, 1});
  Foo<bool> f(a);
  f.at(1) = true;
  cout << f.at(0) << " " << f.at(1) << endl;

  vector<ll> a2({1, 0, 1});
  Foo<ll> f2(a2);
  f2.at(1) = 1;
  cout << f2.at(0) << " " << f2.at(1) << endl;

  vector<bool> a3({1, 0, 1});
  const Foo<bool> f3(a3);
  // f3.at(1) = true;
  cout << f3.at(0) << " " << f3.at(1) << endl;

  return 0;
}
