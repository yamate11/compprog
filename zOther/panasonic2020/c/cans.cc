#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_bin_float.hpp>
using namespace std;
using namespace boost::multiprecision;
using mydouble = cpp_bin_float_100;

int main(int argc, char *argv[]) {
  mydouble err("1e-900");
  // mydouble err = 1e-900
  cerr << setprecision(100) << err << endl;
  mydouble a, b, c; cin >> a >> b >> c;
  cout << (sqrt(a) + sqrt(b) + err < sqrt(c) ? "Yes" : "No") << endl;
  return 0;
}

