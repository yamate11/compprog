#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

constexpr int N = 1e8;

vector<int> foo(int z) {
  vector<int> v(N);
  v.at(N-1) = z;
  return v;
}

int main() {
  vector<int> vv;
  // vv = foo(5);

  vv.resize(0);
  vv.resize(N);
  vv.at(N-1) = 9;

  cout << vv.at(N-1) << " " << vv.at(N-1) << endl;
  return 0;
}
