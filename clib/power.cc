#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/* 
   Power functions.   Time complexity is O(log b).

   The implementation refers to one<T>().  Thus, basic types such as int and double are supported, as well as
   mod classes.  To use this for your own class, define it using MyAlg<Op> in algOp.cc.
 */

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN(algOp) ---- power.cc

template<typename T>
T power(const T& a, ll b) {
  auto two_pow = a;
  auto ret = one<T>(a);
  while (b > 0) {
    if (b & 1LL) ret *= two_pow;
    two_pow *= two_pow;
    b >>= 1;
  }
  return ret;
}

// @@ !! END ---- power.cc
