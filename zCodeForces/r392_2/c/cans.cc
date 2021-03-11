#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m, k, x, y; cin >> n >> m >> k >> x >> y; x--; y--;
  ll vmax, vmin, vxy;
  if (n == 1) {
    ll n_round = k / m;
    if (k % m == 0) {
      vmax = n_round;
      vmin = n_round;
    }else {
      vmax = n_round + 1;
      vmin = n_round;
    }
    if (k % m <= y) vxy = n_round;
    else            vxy = n_round + 1;
  }else if (n == 2) {
    ll n_round = k / (2 * m);
    if (k % (2 * m) == 0) {
      vmax = n_round;
      vmin = n_round;
    }else {
      vmax = n_round + 1;
      vmin = n_round;
    }
    if (k % (2 * m) <= x * m + y) vxy = n_round;
    else                          vxy = n_round + 1;
  }else {
    ll size_round = m * (n - 1) * 2;
    ll n_round = k / size_round;
    ll rem = k % size_round;
    if (n_round == 0) {
      vmax = 1; vmin = 0;
      if (k >= n * m) vmin = 1;
      if (k >= n * m + 1) vmax = 2;

      if (k <= x * m + y) vxy = 0;
      else vxy = 1;
      if (x != 0 && x != n - 1 && k > (2 * n - 2 - x) * m + y) vxy = 2;
    }else if (n_round >= 1) {
      vmax = 2 * n_round; vmin = n_round;
      if (rem >= m + 1) vmax = 2 * n_round + 1;
      if (rem >= n * m ) vmin = n_round + 1;
      if (rem >= n * m + 1) vmax = 2 * n_round + 2;
      ll xy_add = 0;

      if (rem <= x * m + y) xy_add = 0;
      else xy_add = 1;
      if (x != 0 && x != n - 1 && rem > (2 * n - 2 - x) * m + y) xy_add = 2;

      if (x == 0 || x == n - 1) vxy = n_round + xy_add;
      else vxy = 2 * n_round + xy_add;
    }
  }
  cout << vmax << " " << vmin << " " << vxy << endl;

  return 0;
}

