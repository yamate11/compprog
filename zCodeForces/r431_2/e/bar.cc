#include <bits/stdc++.h>

template <typename f_t>
struct A {
  f_t f;           // (1)
  int k;
  A(f_t arg_f, int arg_k) : f(arg_f), k(arg_k) {}    // (2)
  int g(int x) { return f(f(x)) + k; }
};

int main() {
  int p, q; std::cin >> p >> q;
  auto f1 = [&](int x) -> int { return p * x + q; };
  auto f2 = [&](int x) -> int { return p * x - q; };
  std::vector<A<decltype(f1)>> vec_a1;    // (3)
  std::vector<A<decltype(f2)>> vec_a2;
  for (int i = 0; i < 10000; i++) {
    int k; std::cin >> k;
    vec_a1.emplace_back(f1, k);
    vec_a2.emplace_back(f2, k);
  }
  // ....

  return 0;
}

