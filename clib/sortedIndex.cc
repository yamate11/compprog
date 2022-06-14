#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  sortedIndex

  sortedIndex(vec) returns a vector<int> p so that vec[p[0]], vec[p[1]], ..., vec[p[n-1]] is sorted.

  Usage:
    vector<string> vec = {"ttt", "zzz", "eee"};
    auto p = sortedIndex(vec);                     // p == vector<int>({2, 0, 1})
    auto q = sortedIndex(vec, greater<string>());  // q == vector<int>({1, 0, 2})
    for (int i = 0; i < 3; i++) cout << vec[p[i]] << "\n";   // prints "eee", "ttt", "zzz"

*/

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- sortedIndex.cc

vector<int> sortedIndex(const auto& vec, auto comp) {
  vector<int> ret(vec.size());
  iota(ret.begin(), ret.end(), 0);
  sort(ret.begin(), ret.end(), [&vec, &comp](int i, int j) { return comp(vec[i], vec[j]); });
  return ret;
}

template<typename Collection>
vector<int> sortedIndex(const Collection& vec) { return sortedIndex(vec, less<typename Collection::value_type>()); }

// @@ !! END ---- sortedIndex.cc
