#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

ll solve() {
  ll x; cin >> x;
  ll cnt = x / 11;
  x = x % 11;
  if (x == 0) return 2 * cnt;
  if (x <= 6) return 2 * cnt + 1;
  return 2 * cnt + 2;
  
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << solve() << endl;

  return 0;
}

