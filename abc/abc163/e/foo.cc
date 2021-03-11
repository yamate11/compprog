#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int main() {
  std::pair p(2, 4.5);     // deduces to std::pair<int, double> p(2, 4.5);
  std::tuple t(4, 3, 2.5); // same as auto t = std::make_tuple(4, 3, 2.5);
  std::less l;             // same as std::less<void> l;
  return 0;
}

