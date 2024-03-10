#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

template<typename T>
T id_func(T x) { return x; };

template<typename F>
auto vector_from_func(int n, F f) -> vector<decltype(f(0))> {
  vector<decltype(f(0))> ret(n);
  for (int i = 0; i < n; i++) ret[i] = f(i);
  return ret;
}

template<typename CMP>
vector<int> order_vec(int n, CMP cmp) {
  auto ord = vector_from_func(n, id_func<ll>);
  sort(ALL(ord), cmp);
  return ord;
}

typename<bool reverse = false> 
vector<int> order_vec_key_vec(const auto& vec) {
  return order_vec(ssize(vec), [](int a, int b) -> bool {
    if constexpr (reverse) swap(a, b);
    return vec[a] < vec[b];
  });
}

typename<bool reverse = false> 
vector<int> order_vec_key_func(int n, auto f) {
  return order_vec(n, [](int a, int b) -> bool {
    if constexpr (reverse) swap(a, b);
    return f(a) < f(b);
  });
}

auto ord1 = order_vec(ssize(vec), [&](int a, int b) -> bool { return vec[a] < vec[b]; });
auto ord2 = order_vec_key_vec(vec);
auto ord3 = order_vec_key_func(ssize(vec), [&](int a) -> ll { return vec[a]; });


int main() {
  auto vec = vector_from_func(10, id_func<ll>);
  cout << vec[5] << endl;

  return 0;
}
