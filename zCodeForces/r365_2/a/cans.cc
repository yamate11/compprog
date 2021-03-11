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
  ll cnt = 0;
  for (ll i = 0; i < n; i++) {
    ll m, c; cin >> m >> c;
    if (m > c) cnt++;
    if (m < c) cnt--;
  }
  string msg;
  if (cnt > 0) msg = "Mishka";
  if (cnt < 0) msg = "Chris";
  if (cnt == 0) msg = "Friendship is magic!^^";
  cout << msg << endl;

  return 0;
}

