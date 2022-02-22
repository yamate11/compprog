#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

struct A {
  int dimI;
  int dimJ;
  vector<int> mem;
  A() : dimI(1), dimJ(1), mem({{0}}) {}

  template<typename T> void _from_mem(int dimI_, int dimJ_, T&& mem_) {
    dimI = dimI_; dimJ = dimJ_; mem = forward<T>(mem_);
  }
  A(const vector<int>& vec) { _from_mem(1, vec.size(), vec); }
  A(vector<int>&& vec) { _from_mem(1, vec.size(), move(vec)); }
  void _from_vvec(const vector<vector<int>>& vvec) {
    int dimI_ = vvec.size();
    int dimJ_ = vvec[0].size();
    vector<int> flat(dimI_ * dimJ_);
    for (int i = 0; i < dimI_; i++) for (int j = 0; j < dimJ_; j++) flat[i*dimJ_ + j] = vvec[i][j];
    _from_mem(dimI_, dimJ_, move(flat));
  }
  A(const vector<vector<int>>& vvec) { _from_vvec(vvec); }
  A(initializer_list<int> il) { _from_mem(1, il.size(), vector<int>(il)); }
  A(initializer_list<initializer_list<int>> il) {
    vector<vector<int>> vvec(il.size());
    ll i = 0;
    for (auto it : il) {
      vector<int> v(it);
      vvec[i++] = move(v);
    }
    _from_vvec(vvec);
  }
};

int main() {
  vector<int> vec1({3, 4, 5});
  vector<int> vec2({10, 11, 12});
  vector<vector<int>> vvec10({{1, 2}, {3, 4}});
  A a1(vec1);
  A a2(vec2);
  A a10(vvec10);
  A a20({6, 7, 8});
  A a21({{9, 10}, {11, 12}});
  cout << vec1[1] << endl;
  cout << vec2[1] << endl;
}
