#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// sieve(upto) returns the list of prime numbers up to upto.
vector<int> sieve(int upto) {
  vector<int> res;
  vector<bool> tbl(upto+1);
  ll lim = (int)(sqrt((double)upto)) + 1;
  for (int x = 2; x <= upto; x++) {
    if (tbl.at(x))  continue;
    res.push_back(x);
    if (x > lim)  continue;
    for (int y = x * 2; y <= upto; y += x) tbl.at(y) = true;
  }
  return res;
}

int main() {
  int n; cin >> n;
  int x = 1;
  for (int i = 0; i < n; i++) x *= 10;
  cout << sieve(x).size() << endl;
  return 0;
}
