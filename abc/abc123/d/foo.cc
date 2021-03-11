#include <bits/stdc++.h>
#include <cassert>
#include <boost/optional.hpp>
#include <boost/optional/optional_io.hpp>
typedef long long int ll;
using namespace std;

boost::optional<int> foo(int x) {
  if (x % 2 == 0) {
    return x / 2;
  }else {
    return boost::optional<int>();
  }
}

int main() {
  boost::optional<int> y = foo(2);
  boost::optional<int> z = foo(1);
  cout << y << " " << z << endl;
  return 0;
}
