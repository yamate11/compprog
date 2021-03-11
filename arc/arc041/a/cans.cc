#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


ll solve() {
  ll x, y, k ; cin >> x >> y >> k;
  if (k <= y) return x + k;
  return x + y - (k - y);
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << solve() << endl;

  return 0;
}

