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
  ll dimI;
  ll dimJ;
  vector<int> mem;
  A() : dimI(1), dimJ(1), mem({{0}}) {}

  A(const vector<int>& vec) { _from_vec(vec); }
  A(vector<int>&& vec) { _from_vec(move(vec)); }
  A& operator =(const vector<int>& vec) { _from_vec(vec); return *this; }
  A& operator =(vector<int>&& vec)  { _from_vec(move(vec)); return *this; }
  template<typename T> void _from_vec(T&& vec) {
    dimI = 1;
    dimJ = vec.size();
    mem = forward<T>(vec);
  }

  A(const vector<vector<int>>& vvec) { _from_vvec(vvec); }
  A(vector<vector<int>>&& vvec) { _from_vvec(move(vvec)); }
  A& operator =(const vector<vector<int>>& vvec) { _from_vvec(vvec); return *this; }
  A& operator =(vector<vector<int>>&& vvec) { _from_vvec(move(vvec)); return *this; }
  template<typename T> void _from_vvec(T&& vvec) {
    dimI = vvec.size();
    dimJ = vvec[0].size();
    mem.resize(dimI * dimJ);
    for (ll i = 0; i < dimI; i++) for (ll j = 0; j < dimJ; j++) mem[i * dimJ + j] = vvec[i][j];
  }

};

int main() {
  vector<int> vec1({3, 4, 5});
  vector<int> vec2({10, 11, 12});
  vector<vector<int>> vvec10({{1, 2}, {3, 4}});
  A a1(vec1);
  A a2(vec2);
  A a10(vvec10);
  cout << vec1[1] << endl;
  cout << vec2[1] << endl;
}
