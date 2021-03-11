#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long;

////////////////////
// Maximum and Minimum values for types

void sect_consts_max_min() {
  int i1 = INT_MAX;
  int i2 = INT_MIN;
  long long l1 = LLONG_MAX;
  long long l2 = LLONG_MIN;
  double d1 = DBL_MAX;
  double d2 = DBL_MIN;

  assert(i1 == (((1 << 30) - 1) << 1) + 1);
  assert(l1 == (2 * ((1LL << 62) - 1) + 1));
  assert(i2 == -i1 - 1);
  assert(l2 == -l1 - 1);
  assert(1e308 < d1);
  assert(0 < d2 && d2 < 3e-308);
}

////////////////////
// Formatted output

void sect_format() {
  {
    stringstream ss;
    ss << 100; assert(ss.str() == "100");
  }{
    stringstream ss; 
    ss << hex << 253 << uppercase << 254 << nouppercase << 255;
    assert(ss.str() == "fdFEff");
  }{
    stringstream ss;
    double x = 1.0 / 3.0;
    ss << x << " " << setprecision(20) << x;
    assert(ss.str() == "0.333333 0.33333333333333331483");
  }{
    stringstream ss, ss1;
    ss << setw(4) << 10 << "," << setw(4) << (int)1e8;
    assert(ss.str()  == "  10,100000000");
    ss1 << setfill('0') << setw(4) << 10 << "," << setw(4) << (int)1e8;
    assert(ss1.str() == "0010,100000000");
  }{
    stringstream ss1, ss2;
    // Almost all manipulator are sticky:
    ss1 << hex << 100 << " " << 200;
    assert(ss1.str() == "64 c8");
    // But setw() is an exception.
    ss2 << setw(4) << 5 << 6;
    assert(ss2.str() == "   56");
  }
  
  // For other manipulators, see:
  // https://www.cs.fsu.edu/~myers/c++/notes/formatting.html

}

////////////////////
// Nested vector (multi-dimensional vector) declaration

using Vec1 = vector<ll>;
using Vec2 = vector<Vec1>;
using Vec3 = vector<Vec2>;
using Vec4 = vector<Vec3>;

void sect_nested_vector() {
  ll N = 10;
  Vec4 w(N, Vec3(N, Vec2(N, Vec1(N, -1))));
  w.at(0).at(1).at(2).at(3) = 5;
  assert(w.at(0).at(1).at(2).at(3) + w.at(N-1).at(N-1).at(N-1).at(N-1) == 4);
}

////////////////////
// How to use exceptions

struct MyException : exception {};

void exception_func1(int x) {
  if (x == 1) throw MyException();
}

void sect_exception() {
  int i;
  try {
    for (i = 0; i < 2; i++) exception_func1(i);
  }catch(const MyException& e) {
  }
  assert(i == 1);
}

////////////////////
// lower bound and upper bound

void sect_lower_upper_bound() {
  //             0  1  2  3  4  5
  vector<int> v({2, 4, 6, 6, 6, 8});
  auto b = v.begin();
  auto e = v.end();

  // We assume a total order.

  // If x does not exist in v,
  // lower_bound and upper_bound return the same position
  // I.e., the minimum value in v which is greater than x.
  assert(lower_bound(b, e, 5) == b + 2);
  assert(upper_bound(b, e, 5) == b + 2);

  // If x exists in v,
  // lower_bound returns the first position of such elements.
  assert(lower_bound(b, e, 6) == b + 2);
  // upper_bound returns the first position after such elements.
  assert(upper_bound(b, e, 6) == b + 5);

  // In particular, if x is greater than every element in v,
  // e is returned.
  assert(lower_bound(b, e, 9) == e);
  assert(upper_bound(b, e, 9) == e);
}

////////////////////
// Erasing set elements

void sect_erase_set() {

  // erase(Iterator) and erase(Iterator, Iterator) returns the
  // position next to the erased elements.
  set<int> s1({5,6,7,8,9});
  auto it1 = s1.erase(s1.find(6), s1.find(8));
  assert(it1 == s1.find(8));
  it1 = s1.erase(s1.find(9));
  assert(it1 == s1.end());

  // Therefore, you can safely erase elements while running a loop:
  set<int> s2({1,2,3,4,5});
  for (auto it = s2.begin(); it != s2.end(); ) {
    if (*it % 2 == 0) it = s2.erase(it);
    else              it++;
  }
  assert(s2 == set<int>({1,3,5}));

  // The range-based for should not be used.
#if 0
  set<int> s3({1,2,3,4,5});
  for (int t : s3) {
    if (t % 2 == 0) s3.erase(t); // may cause a memory error.
  }
#endif

}

////////////////////
// Reverse iterators for sets

void sect_reverse_iterator_set() {

  stringstream ss;
  set<int> s({4, 5, 6, 7, 8, 9});
  int x = 6;

  // Task: printing values larger than or equal to x in a set<int>
  // A natural solution:
  for (auto it = s.lower_bound(x); it != s.end(); it++) ss << *it;
  
  // Task: printing values smaller than or equal to x in a set<int>
  //       in reverse order
  // Solution:
  auto it0 = s.upper_bound(x);
  auto revit = reverse_iterator<decltype(it0)>(it0);
    // We cannot omit T in reverse_iterator<T>.  So decltype() is handy.
    // Note that reverse_iterator() shifts the argument iterator (it0, in
    // this case) to the left-next position.  (Remember, e.g., that
    // s.rend() points to the left-next position of s.begin().)
    // Therefore, upper_bound should be used.
  for (; revit != s.rend(); revit++) ss << *revit;

  assert(ss.str() == "6789654");
}

////////////////////
// Using a lambda function in priority queue declarations

void sect_lambda_priority_queue() {

  vector<int> x({1000, 0, 500, 0, 300});

  // A priority queue with priority x.at(*)
  auto comp = [&](int i, int j) { return x.at(i) < x.at(j); };
  priority_queue<int, vector<int>, decltype(comp)> pque(comp);
  // Naturally, care should be taken when you change the value x.at(*)
  // so that it is consistent with the queue contents.

  pque.push(3);
  pque.push(0);
  pque.push(4);
  int y;
  y = pque.top(); pque.pop(); assert(y == 0);
  y = pque.top(); pque.pop(); assert(y == 4);
  y = pque.top(); pque.pop(); assert(y == 3);

}

////////////////////
// GCC built-in functions for bit counting

void sect_gcc_builtin() {

  // __builtin_popcountll(x) ... the number of 1-bits
  assert(__builtin_popcountll(0xF) == 4);
  assert(__builtin_popcountll(0x100030007000F000) == 10);

  // __builtin_ctzll(x) ... the number of trailing 0-bits.
  //           i.e.  index of the LSB.
  //           x must not be 0
  assert(__builtin_ctzll(0x1) == 0);
  assert(__builtin_ctzll(0x8) == 3);
  assert(__builtin_ctzll(1LL<<63) == 63);

  // __builtin_clzll(x) ... the numberof leading 0-bits.
  //           i.e.  63 - index of the MSB.
  //           x must not be 0
  assert(__builtin_clzll(0x1) == 63);
  assert(__builtin_clzll(1LL<<62) == 1);

}



////////////////////

int main() {
  sect_consts_max_min();
  sect_format();
  sect_nested_vector();
  sect_exception();
  sect_lower_upper_bound();
  sect_erase_set();
  sect_reverse_iterator_set();
  sect_lambda_priority_queue();
  sect_gcc_builtin();

  return 0;
}




///////////////////
/* 定数
   INT_MAX    2147483647              ( 2.1e+9)
   INT_MIN    -2147483648             (-2.1e+9)
   LLONG_MAX  9223372036854775807     ( 9.2e+18)
   LLONG_MIN  -9223372036854775808    (-9.2e+18)
   DBL_MAX    1.797e+308
   DBL_MIN    2.225e-308
   LDBL_MAX   1.189e+4932
   LDBL_MIN   3.362e-4932
 */


/* サイズ

2項係数
 1     1     1
 2     1     2     1
 3     1     3     3     1
 4     1     4     6     4     1
 5     1     5    10    10     5     1
 6     1     6    15    20    15     6     1
 7     1     7    21    35    35    21     7     1
 8     1     8    28    56    70    56    28     8     1
 9     1     9    36    84   126   126    84    36     9     1
10     1    10    45   120   210   252   210   120    45    10     1
11     1    11    55   165   330   462   462   330   165    55    11     1
12     1    12    66   220   495   792   924   792   495   220    66    12     1
13     1    13    78   286   715  1287  1716  1716  1287   715   286    78    13     1
14     1    14    91   364  1001  2002  3003  3432  3003  2002  1001   364    91    14     1
15     1    15   105   455  1365  3003  5005  6435  6435  5005  3003  1365   455   105    15     1
16     1    16   120   560  1820  4368  8008 11440 12870 11440  8008  4368  1820   560   120    16     1

累乗，組合せ
2 **  1 = 2.00e+00,  C( 1,  0) = 1.00e+00
2 **  2 = 4.00e+00,  C( 2,  1) = 2.00e+00
2 **  3 = 8.00e+00,  C( 3,  1) = 3.00e+00
2 **  4 = 1.60e+01,  C( 4,  2) = 6.00e+00
2 **  5 = 3.20e+01,  C( 5,  2) = 1.00e+01
2 **  6 = 6.40e+01,  C( 6,  3) = 2.00e+01
2 **  7 = 1.28e+02,  C( 7,  3) = 3.50e+01
2 **  8 = 2.56e+02,  C( 8,  4) = 7.00e+01
2 **  9 = 5.12e+02,  C( 9,  4) = 1.26e+02
2 ** 10 = 1.02e+03,  C(10,  5) = 2.52e+02
2 ** 11 = 2.05e+03,  C(11,  5) = 4.62e+02
2 ** 12 = 4.10e+03,  C(12,  6) = 9.24e+02
2 ** 13 = 8.19e+03,  C(13,  6) = 1.72e+03
2 ** 14 = 1.64e+04,  C(14,  7) = 3.43e+03
2 ** 15 = 3.28e+04,  C(15,  7) = 6.44e+03
2 ** 16 = 6.55e+04,  C(16,  8) = 1.29e+04
2 ** 17 = 1.31e+05,  C(17,  8) = 2.43e+04
2 ** 18 = 2.62e+05,  C(18,  9) = 4.86e+04
2 ** 19 = 5.24e+05,  C(19,  9) = 9.24e+04
2 ** 20 = 1.05e+06,  C(20, 10) = 1.85e+05
2 ** 21 = 2.10e+06,  C(21, 10) = 3.53e+05
2 ** 22 = 4.19e+06,  C(22, 11) = 7.05e+05
2 ** 23 = 8.39e+06,  C(23, 11) = 1.35e+06
2 ** 24 = 1.68e+07,  C(24, 12) = 2.70e+06
2 ** 25 = 3.36e+07,  C(25, 12) = 5.20e+06
2 ** 26 = 6.71e+07,  C(26, 13) = 1.04e+07
2 ** 27 = 1.34e+08,  C(27, 13) = 2.01e+07
2 ** 28 = 2.68e+08,  C(28, 14) = 4.01e+07
2 ** 29 = 5.37e+08,  C(29, 14) = 7.76e+07
2 ** 30 = 1.07e+09,  C(30, 15) = 1.55e+08
2 ** 31 = 2.15e+09,  C(31, 15) = 3.01e+08
2 ** 32 = 4.29e+09,  C(32, 16) = 6.01e+08
2 ** 33 = 8.59e+09,  C(33, 16) = 1.17e+09
2 ** 34 = 1.72e+10,  C(34, 17) = 2.33e+09
2 ** 35 = 3.44e+10,  C(35, 17) = 4.54e+09
2 ** 36 = 6.87e+10,  C(36, 18) = 9.08e+09
2 ** 37 = 1.37e+11,  C(37, 18) = 1.77e+10
2 ** 38 = 2.75e+11,  C(38, 19) = 3.53e+10
2 ** 39 = 5.50e+11,  C(39, 19) = 6.89e+10
2 ** 40 = 1.10e+12,  C(40, 20) = 1.38e+11
2 ** 41 = 2.20e+12,  C(41, 20) = 2.69e+11
2 ** 42 = 4.40e+12,  C(42, 21) = 5.38e+11
2 ** 43 = 8.80e+12,  C(43, 21) = 1.05e+12
2 ** 44 = 1.76e+13,  C(44, 22) = 2.10e+12
2 ** 45 = 3.52e+13,  C(45, 22) = 4.12e+12
2 ** 46 = 7.04e+13,  C(46, 23) = 8.23e+12
2 ** 47 = 1.41e+14,  C(47, 23) = 1.61e+13
2 ** 48 = 2.81e+14,  C(48, 24) = 3.22e+13
2 ** 49 = 5.63e+14,  C(49, 24) = 6.32e+13
2 ** 50 = 1.13e+15,  C(50, 25) = 1.26e+14
2 ** 51 = 2.25e+15,  C(51, 25) = 2.48e+14
2 ** 52 = 4.50e+15,  C(52, 26) = 4.96e+14
2 ** 53 = 9.01e+15,  C(53, 26) = 9.73e+14
2 ** 54 = 1.80e+16,  C(54, 27) = 1.95e+15
2 ** 55 = 3.60e+16,  C(55, 27) = 3.82e+15
2 ** 56 = 7.21e+16,  C(56, 28) = 7.65e+15
2 ** 57 = 1.44e+17,  C(57, 28) = 1.50e+16
2 ** 58 = 2.88e+17,  C(58, 29) = 3.01e+16
2 ** 59 = 5.76e+17,  C(59, 29) = 5.91e+16
2 ** 60 = 1.15e+18,  C(60, 30) = 1.18e+17
2 ** 61 = 2.31e+18,  C(61, 30) = 2.33e+17
2 ** 62 = 4.61e+18,  C(62, 31) = 4.65e+17
2 ** 63 = 9.22e+18,  C(63, 31) = 9.16e+17
2 ** 64 = 1.84e+19,  C(64, 32) = 1.83e+18

階乗
 1 1.0e+00                                    1
 2 2.0e+00                                    2
 3 6.0e+00                                    6
 4 2.4e+01                                   24
 5 1.2e+02                                  120
 6 7.2e+02                                  720
 7 5.0e+03                                 5040
 8 4.0e+04                                40320
 9 3.6e+05                               362880
10 3.6e+06                              3628800
11 4.0e+07                             39916800
12 4.8e+08                            479001600
13 6.2e+09                           6227020800
14 8.7e+10                          87178291200
15 1.3e+12                        1307674368000
16 2.1e+13                       20922789888000
17 3.6e+14                      355687428096000
18 6.4e+15                     6402373705728000
19 1.2e+17                   121645100408832000
20 2.4e+18                  2432902008176640000
21 5.1e+19                 51090942171709440000
22 1.1e+21               1124000727777607680000
23 2.6e+22              25852016738884976640000
24 6.2e+23             620448401733239439360000
25 1.6e+25           15511210043330985984000000
26 4.0e+26          403291461126605635584000000
27 1.1e+28        10888869450418352160768000000
28 3.0e+29       304888344611713860501504000000
29 8.8e+30      8841761993739701954543616000000
30 2.7e+32    265252859812191058636308480000000
31 8.2e+33   8222838654177922817725562880000000
32 2.6e+35 263130836933693530167218012160000000


 */
/*
  初項 a >= 0, 公差 -d (d > 0) の等差数列の正の部分の和
    S = (a + a%d) * (a + d - a%d) / d
 */
