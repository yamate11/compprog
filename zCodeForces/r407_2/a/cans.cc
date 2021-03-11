#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, k; cin >> n >> k;
  ll cnt = 0;
  for (ll i = 0; i < n; i++) {
    ll x; cin >> x;
    cnt += (x + (k-1)) / k;
  }
  cout << (cnt + 1) / 2 << endl;


  return 0;
}

