#if __INCLUDE_LEVEL__ == 0

#include __BASE_FILE__

void Solve() {
  int n, m, l;
  IN(n, m, l);
  vector<int> a(l);
  IN(a);
  vector<vector<int>> g(n);
  for (int _ : Rep(0, m)) {
    int i, j;
    IN(i, j);
    --i, --j;
    g[i].push_back(j);
    g[j].push_back(i);
  }

  vector dist(2, vector<int>(n, INF));
  vector<pair<int, int>> q;
  q.reserve(2 * n);
  auto push = [&](int p, int i, int d) {
    if (SetMin(dist[p][i], d)) {
      q.emplace_back(p, i);
    }
  };
  push(0, 0, 0);
  for (int qi = 0; qi < Sz(q); ++qi) {
    auto [p, i] = q[qi];
    for (int j : g[i]) {
      push(p ^ 1, j, dist[p][i] + 1);
    }
  }

  string ans(n, '0');
  int sum_a = reduce(ALL(a));
  for (int i : Rep(0, n)) {
    if (dist[sum_a & 1][i] < INF) {
      if (dist[sum_a & 1][i] <= sum_a) {
        ans[i] = '1';
      }
    }
  }
  int min_odd = INF;
  for (int e : a) {
    if (e & 1) {
      SetMin(min_odd, e);
    }
  }
  if (min_odd < INF) {
    sum_a -= min_odd;
    for (int i : Rep(0, n)) {
      if (dist[sum_a & 1][i] < INF) {
        if (dist[sum_a & 1][i] <= sum_a) {
          ans[i] = '1';
        }
      }
    }
  }

  OUT(ans);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  IN(t);
  while (t--) {
    Solve();
  }
}

#elif __INCLUDE_LEVEL__ == 1

#include <bits/stdc++.h>

template <class T> concept MyRange = std::ranges::range<T> && !std::convertible_to<T, std::string_view>;
template <class T> concept MyTuple = std::__is_tuple_like<T>::value && !MyRange<T>;

namespace std {

istream& operator>>(istream& is, MyRange auto&& r) {
  for (auto&& e : r) is >> e;
  return is;
}
istream& operator>>(istream& is, MyTuple auto&& t) {
  apply([&](auto&... xs) { (is >> ... >> xs); }, t);
  return is;
}

ostream& operator<<(ostream& os, MyRange auto&& r) {
  auto sep = "";
  for (auto&& e : r) os << exchange(sep, " ") << e;
  return os;
}
ostream& operator<<(ostream& os, MyTuple auto&& t) {
  auto sep = "";
  apply([&](auto&... xs) { ((os << exchange(sep, " ") << xs), ...); }, t);
  return os;
}

}  // namespace std

using namespace std;

#define _ _ [[maybe_unused]]
#define LAMBDA2(x, y, ...) ([&](auto&& x, auto&& y) -> decltype(auto) { return __VA_ARGS__; })
#define ALL(r) begin(r), end(r)
#define Rep(...) [](int l, int r) { return views::iota(min(l, r), r); }(__VA_ARGS__)
#define Sz(r) int(size(r))
#define SetMin(...) LAMBDA2(x, y, y < x && (x = y, 1))(__VA_ARGS__)
#define INF (INT_MAX / 2)
#define IN(...) (cin >> forward_as_tuple(__VA_ARGS__))
#define OUT(...) (cout << forward_as_tuple(__VA_ARGS__) << '\n')

#endif  // __INCLUDE_LEVEL__ == 1
