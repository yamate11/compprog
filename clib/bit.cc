#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  Binary Indexed Tree
  Type T should have operator + and cast from int ((T)0)
  
  Usage:
    BIT<long long> t(10); // a_1 = a_2 = ... = a_10 = 0
    for (int i = 1; i <= 10; i++)  t.add(i, i);  // a_i = i
    t.add(1, 300);           // a_1 <- a_1 + 300 = 301
    long long x = t.sum(3);  // x <- a_1 + a_2 + a_3 = 301 + 2 + 3 = 306
*/

//////////////////////////////////////////////////////////////////////
// @@ !! BEGIN() ---- bit.cc

template <class T>
class BIT {
  int size; // the number of slots
  vector<T> vec; // from 1 to size

public:

  BIT(int s) : size(s), vec(s+1) {}

  void add(int i, T x) {
    while (i <= size) {
      vec.at(i) += x;
      i += (i & (-i));
    }
  }

  T sum(int i) {
    T res = (T)0;
    while (i >= 1) {
      res += vec.at(i);
      i -= (i & (-i));
    }
    return res;
  }

};

// @@ !! END ---- bit.cc

int main() {
  BIT<long long> t(10); // a_1 = a_2 = ... = a_10 = 0
  for (int i = 1; i <= 10; i++)  t.add(i, i);  // a_i = i
  t.add(1, 300);           // a_1 <- a_1 + 300 = 301
  long long x = t.sum(3);  // x <- a_1 + a_2 + a_3 = 301 + 2 + 3 = 306
  assert(x == 306);
}
