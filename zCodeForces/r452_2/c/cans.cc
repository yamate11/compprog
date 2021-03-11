#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  ll diff = -1;
  ll start = -1;
  ll extra = -1;
  ll r1, r2;
  if (n % 4 == 0) {
    diff = 0;
    start = 1;
    extra = -1;
    r1 = 0;
    r2 = 1;
  }else if (n % 4 == 1) {
    diff = 1;
    start = 2;
    extra = -1;
    r1 = 0;
    r2 = 3;
  }else if (n % 4 == 2) {
    diff = 1;
    start = 3;
    extra = 1;
    r1 = 3;
    r2 = 2;
  }else if (n % 4 == 3) {
    diff = 0;
    start = 4;
    extra = 3;
    r1 = 0;
    r2 = 3;
  }
  vector<ll> grp;
  if (extra >= 0) grp.push_back(extra);
  for (ll i = start; i <= n; i++) {
    if (i % 4 == r1 || i % 4 == r2) grp.push_back(i);
  }
  cout << diff << endl;
  cout << grp.size();
  for (ll i : grp) {
    cout << " " << i;
  }
  cout << endl;
  

  return 0;
}

