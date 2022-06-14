#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(sortedIndex)

using pll = pair<ll, ll>;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    vector<ll> vec1({10, 5, 7, 1, 20, 3});
    auto p = sortedIndex(vec1);
    assert(p == vector<int>({3, 5, 1, 2, 0, 4}));
    auto q = sortedIndex(vec1, greater<ll>());
    assert(q == vector<int>({4, 0, 2, 1, 5, 3}));
  }
  {
    vector<pll> vec1({{7, 3}, {7, 2}, {3, 0}, {4, 4}, {7, 10}, {1, 5}, {3, 2}});
    auto compare = [&](pll x, pll y) -> bool {
      auto [x1, x2] = x;
      auto [y1, y2] = y;
      if (x1 != y1) return x1 < y1;
      else          return x2 > y2;
    };
    auto p = sortedIndex(vec1, compare);
    for (size_t i = 0; i < vec1.size() - 1; i++) {
      assert(not compare(vec1[p[i + 1]], vec1[p[i]]));
    }
  }
           

}
