#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

int func(int x) { return x + 1; }

template<typename T, typename f_t = T (*)(T)>
struct A {
  A(f_t f_) : f(f_) {}
  f_t f;
  T g(T x) { return f(f(x)); }
};


int main() {
  auto h = [&](int x) -> int { return x + 1; };
  A<int, decltype(h)> a(h);
  cout << a.f(0) << a.g(1) << endl;
}
