#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug perm)


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
    auto prev = perm.get();
    while (true) {
      if (!perm.next()) break;
      cnt++;
      auto cur = perm.get();
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
    sanity_perm(ip, 6*5*4*3);
  }
  {
    IntPerm ip(5);
    sanity_perm(ip, 5*4*3*2*1);
  }
  {
    vector<int> v(4);
    iota(v.begin(), v.end(), 1);
    IterPerm<vector<int>> itp(v, 2);
    sanity_perm(itp, 4*3);
  }
  {
    string s("xcde");
    IterPerm<string> itp(s);
    int cnt = 1;
    while (true) {
      if (!itp.next()) break;
      cnt++;
    }
    assert(cnt == 4*3*2*1);
  }
  {
    IntComb ic(5, 2);
    sanity_perm(ic, (5*4)/(2*1));
  }
  {
    DupIntPerm dip(3, 5);
    const auto& vec = dip.get();
    assert(vec.size() == 5);
    int i = 0;
    do {
      int x = i;
      for (int j = 0; j < 5; j++) {
        assert(x % 3 == vec[4 - j]);
        x /= 3;
      }
      i++;
    }while (dip.next());
  }
  {
    vector<int> vec({5, 10, 3, 6});
    IterComb itc(vec, 2);
    vector<vector<int>> exp({{5,10},{5,3},{5,6},{10,3},{10,6},{3,6}});
    int i = 0;
    const auto& v = itc.get();
    do {
      assert(v == exp.at(i++));
    }while (itc.next());
    assert(i == 6);
  }


  cerr << "Test Done.\n";

}
