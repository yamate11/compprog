#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int solve(ll x, ll y) {
  ll m = LLONG_MAX;
  if (x - y >= 0) m = min(x - y + 2, m);
  if (-x - y >= 0) m = min(-x - y + 1, m);
  if (x + y >= 0) m = min(x + y + 1, m);
  if (y - x >= 0) m = min(y - x, m);
  return m;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  int x, y; cin >> x >> y;
  cout << solve(x, y) << endl;
  return 0;
}

