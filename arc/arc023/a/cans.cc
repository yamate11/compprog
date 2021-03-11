#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

ll formula(ll y, ll m, ll d) {
  if (m <= 2) {
    y--;
    m += 12;
  }
  return 365 * y + (y / 4) - (y / 100) + (y / 400) +
    ((306 * (m + 1)) / 10) + d - 429;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll y, m, d; cin >> y >> m >> d;
  cout << formula(2014, 5, 17) - formula(y, m, d) << endl;

  return 0;
}

