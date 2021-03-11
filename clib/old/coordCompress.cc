#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  Coordinate Compress
*/
template <class T>
void coordCompress(vector<T>& x) {
  int n = x.size();
  vector<T> ord(n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(),
       [&](int p, int q) { return x.at(p) < x.at(q); });
  T value = 0;
  for (int i = 0; i < n; i++) {
    T nextValue = (i+1 < n && x.at(ord.at(i)) != x.at(ord.at(i+1)))
                  ? value + 1 : value;
    x.at(ord.at(i)) = value;
    value = nextValue;
  }
}


int main() {
  vector<int> x( {10000, -500, 0, -3000, -500, 10000} );
  vector<int> y( {3, 1, 2, 0, 1, 3} );
  coordCompress<int>(x);
  for (int i = 0; i < 6; i++) assert(x.at(i) == y.at(i));
}
