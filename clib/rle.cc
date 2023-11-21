#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;

/*
  RLE -- Run Length Encoding

  vector<pair<char, int>> rle_string(string s);

  template<class InputIt, class OutputIt>
  OutputIt rle(InputIt first, InputIt last, OutputIt d_first);
      
  Usage:
    const auto& enc = rle_string("aabbbcdd"); // enc == {{'a', 2}, {'b', 3}, {'c', 1}, {'d', 2}}

    vector<int> vec{3, 1, 1, 1, 1, 9, 9};
    vector<pair<int, int>> result;
    rle(vec.begin(), vec.end(), back_inserter(result));  // result == {{3, 1}, {1, 4}, {9, 2}}

 */

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN()    ---- rle.cc

template<class InputIt, class OutputIt>
OutputIt rle(InputIt first, InputIt last, OutputIt d_first) {
  InputIt itA = first;
  OutputIt oit = d_first;
  while (itA != last) {
    InputIt itB = next(itA);
    for (; itB != last and *itA == *itB; itB++);
    *oit = make_pair(*itA, itB - itA);
    itA = itB;
    oit++;
  }
  return oit;
}

vector<pair<char, int>> rle_string(string s) {
  vector<pair<char, int>> ret;
  rle(s.begin(), s.end(), back_inserter(ret));
  return ret;
}

// @@ !! END ---- rle.cc
