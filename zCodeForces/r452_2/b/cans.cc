#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<ll> mon({31,28,31,30,31,30,31,31,30,31,30,31});
  vector<ll> cal(400*12*2);
  for (ll y = 0; y < 400; y++) {
    for (ll m = 0; m < 12; m++) {
      ll idx = y * 12 + m;
      cal[idx] = mon[m];
      if (m == 1) {
        if (y == 0) cal[idx] = 29;
        else if (y % 4 == 0 && y % 100 != 0) cal[idx] = 29;
      }
    }
  }
  for (ll i = 0; i < 400*12; i++) cal[400*12 + i] = cal[i];

  ll n; cin >> n;
  vector<ll> A(n);
  for (ll i = 0; i < n; i++) cin >> A[i];

  for (ll i = 0; i < 400*12; i++) {
    bool succ = true;
    for (ll j = 0; j < n; j++) {
      if (A[j] != cal[i + j]) {
        succ = false;
        break;
      }
    }
    if (succ) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;

  return 0;
}

