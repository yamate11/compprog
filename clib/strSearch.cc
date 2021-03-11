#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
   Z Algorithm  (string search)
*/

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- strSearch.cc
vector<int> zAlg(string s) {
  int n = s.size();
  vector<int> z(n);
  z.at(0) = n;
  int i = 1;
  int j = 0;
  while (i < n) {
    for ( ; i+j < n && s.at(j) == s.at(i+j); j++) {}
    z.at(i++) = j;
    if (j > 0) {
      for (int k = 1; i < n && z.at(k) < j-1; k++, j--, i++) z.at(i) = z.at(k);
      j--;
    }
  }
  return z;
}

// matches("abab", "xababab") --> [1,3]
vector<int> matches(string p, string s, char sepChar = '\xff') {
  auto v = zAlg(p + string(1, sepChar) + s);
  int n = p.size();
  vector<int> res;
  for (size_t i = 0; i < s.size() - (n-1); i++) {
    if (v.at(n+1 + i) == n) res.push_back(i);
  }
  return res;
}
// @@ !! END ---- strSearch.cc



// ----------------------------------------------------------------------
// tests

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
