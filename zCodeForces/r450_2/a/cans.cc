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
  ll cntP = 0;
  ll cntN = 0;
  for (ll i = 0; i < n; i++) {
    ll x, y; cin >> x >> y;
    if (x > 0) cntP++;
    else cntN++;
  }
  if (min(cntP, cntN) <= 1) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }


  return 0;
}

