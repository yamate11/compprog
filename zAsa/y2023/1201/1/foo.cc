#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
using pll = pair<ll, ll>;

template <typename T>
struct A {
  using value_type = T;
};

template <typename T>
void func1(const A<T>& a) {
}

void wrapper(const auto& a) {
  func1<typename remove_reference<decltype(a)>::type::value_type>(a);
}

/*
template<typename T>
T ff(auto f, auto a) {
  return f(a);
}
*/
auto ff(auto g, auto a) {
  return g(a);
}


int g0(int x) {
  return x + 1;
}

template<typename F, typename T>
void funcA(F f, vector<T> v) {
  using S = decltype(f(declval<T>()));
  vector<S> w;
  for (T x : v) w.push_back(f(x));
  cout << w.size() << endl;
}




int main() {
  auto f0 = [&](int a) -> double { return a; };
  vector<int> vec;
  funcA(f0, vec);

  return 0;
}
