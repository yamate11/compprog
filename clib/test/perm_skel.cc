#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(perm)

int cmp_vec(const auto& v1, const auto& v2) {
  ll m = min(v1.size(), v2.size());
  for (int i = 0; i < m; i++) {
    if (v1.at(i) < v2.at(i)) return -1;
    if (v1.at(i) > v2.at(i)) return 1;
  }
  if (v1.size() < v2.size()) return -1;
  if (v1.size() > v2.size()) return 1;
  return 0;
}

void sanity_perm(auto& perm, int exp_cnt) {
    int cnt = 1;
    auto prev = perm.vec_view();
    while (true) {
      if (!perm.get()) break;
      cnt++;
      auto cur = perm.vec_view();
      assert(cmp_vec(prev, cur) == -1);
      prev = move(cur);
    }
    assert(cnt == exp_cnt);
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    IntPerm ip(6, 4);
    ip.get();
    sanity_perm(ip, 6*5*4*3);
  }
  {
    IntPerm ip(5, 5);
    ip.get();
    sanity_perm(ip, 5*4*3*2*1);
  }
  {
    IntComb ic(5, 2);
    ic.get();
    sanity_perm(ic, (5*4)/(2*1));
  }

  using vvi = vector<vector<int>>;
  auto get_all = [&](auto& p) -> vvi {
    vvi ret;
    while (p.get()) ret.push_back(p.vec_view());
    return ret;
  };

  {
    IntPerm p1(3, 2);
    assert(get_all(p1) == vvi({      {0,1},{0,2},{1,0},      {1,2},{2,0},{2,1}      }));
    IntComb p2(3, 2);
    assert(get_all(p2) == vvi({      {0,1},{0,2},            {1,2},                 }));
    IntDupPerm p3(3, 2);
    assert(get_all(p3) == vvi({{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}}));
    IntDupComb p4(3, 2);
    assert(get_all(p4) == vvi({{0,0},{0,1},{0,2},      {1,1},{1,2},            {2,2}}));
  }
  {
    IntDupPerm p1(2, 3);
    assert(get_all(p1) == vvi({{0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1}}));
    IntDupComb p2(2, 3);
    assert(get_all(p2) == vvi({{0,0,0},{0,0,1},{0,1,1},{1,1,1}}));
    IntDupComb p3(3, 3);
    assert(get_all(p3) == vvi({{0,0,0},{0,0,1},{0,0,2},{0,1,1},{0,1,2},{0,2,2},{1,1,1},{1,1,2},{1,2,2},{2,2,2}}));
  }

  auto test_is_empty = [&](auto p) -> void { assert(get_all(p) == vvi{}); };
  auto test_is_single = [&](auto p) -> void { assert(get_all(p) == vvi{{}}); };
  {
    test_is_empty(IntPerm(-3, 2));
    test_is_empty(IntComb(-3, 2));
    test_is_empty(IntDupPerm(-3, 2));
    test_is_empty(IntDupComb(-3, 2));
    test_is_empty(IntPerm(3, -2));
    test_is_empty(IntComb(3, -2));
    test_is_empty(IntDupPerm(3, -2));
    test_is_empty(IntDupComb(3, -2));
    test_is_empty(IntPerm(3, 5));
    test_is_empty(IntComb(3, 5));
    test_is_single(IntPerm(0, 0));
    test_is_single(IntComb(0, 0));
    test_is_single(IntDupPerm(0, 0));
    test_is_single(IntDupComb(0, 0));
    test_is_single(IntPerm(5, 0));
    test_is_single(IntComb(5, 0));
    test_is_single(IntDupPerm(5, 0));
    test_is_single(IntDupComb(5, 0));
  }

  auto test_double = [&](auto p) -> void {
    vector<vector<int>> res1, res2;
    while (p.get()) {
      vector<int> v;
      for (int i = 0; i < p.r; i++) v.push_back(p.at(i));
      res1.push_back(move(v));
    }
    while (p.get()) {
      vector<int> v;
      for (int i = 0; i < p.r; i++) v.push_back(p.at(i));
      res2.push_back(move(v));
    }
    assert(res1 == res2);
  };
  {
    test_double(IntPerm(3, 2));
    test_double(IntComb(7, 3));
    test_double(IntDupPerm(7, 3));
    test_double(IntDupComb(7, 3));
  }

  cerr << "ok\n";

}
