#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(cht)

int main() {

  CHT<int> cht1(vector<int>({-10, 0, 10}));
  cht1.put(0, 3);
  assert(cht1.get(0) == 3);
  cht1.put(-1, 4);
  assert(cht1.get(0) == 4);
  assert(cht1.get(10) == 3);
  assert(cht1.get(-10) == 14);
  cht1.put(1, 2);
  assert(cht1.get(0) == 4);
  assert(cht1.get(10) == 12);
  assert(cht1.get(-10) == 14);

  // Compare the results with naively computed values
  mt19937_64 mt(1234);
  uniform_int_distribution<int> randN(2, 1000), randD(0, 1);
  uniform_real_distribution<double> randA(-1, 1), randB(-1, 1), randX(0, 1);
  for (int zz = 0; zz < 100; zz++) {
    int n = randN(mt);
    vector<double> as(n), bs(n), xs(n);
    vector<bool> eff(n);
    for (int i = 0; i < n; i++) {
      as.at(i) = randA(mt);
      bs.at(i) = randB(mt);
      xs.at(i) = randX(mt);
    }
    CHT<double> chtC(xs);
    for (int i = 0; i < n; i++) {
      if (i == 0 || randD(mt) == 0) {
	chtC.put(as.at(i), bs.at(i));
	eff.at(i) = true;
      }
      if (randD(mt) == 0) {
	double x = xs.at(i);
	double v = 0;
	for (int j = 0; j <= i; j++) {
	  if (!eff.at(j)) continue;
	  double y = as.at(j) * x + bs.at(j);
	  if (j == 0) v = y;
	  else        v = max(v, y);
	}
	assert(v == chtC.get(x));
      }
    }
  }
  
  return 0;
}
