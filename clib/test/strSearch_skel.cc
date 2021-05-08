#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(strSearch)

bool myEqual(auto v1, auto v2) {
  if (v1.size() != v2.size()) return false;
  for (size_t i = 1; i < v1.size(); i++) {
    if (v1.at(i) != v2.at(i)) return false;
  }
  return true;
}

int main() {
  auto v1 = zAlg("aaabaaaab");
  auto e1 = vector<int>({-1,2,1,0,3,4,2,1,0});
  assert(myEqual(v1, e1));
  auto v2 = zAlg("abcxabcyabcxabpz");
  auto e2 = vector<int>({-1,0,0,0,3,0,0,0,6,0,0,0,2,0,0,0});
  assert(myEqual(v2, e2));
  auto v3 = zAlg("abcxabpyabcxabcz");
  auto e3 = vector<int>({-1,0,0,0,2,0,0,0,6,0,0,0,3,0,0,0});
  assert(myEqual(v3, e3));
  
  assert(myEqual(matches("a", "xababa"), vector<int>({1,3,5})));
  assert(myEqual(matches("abab", "xababab"), vector<int>({1,3})));

  return 0;
}
