#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, a; cin >> n >> a; a--;
  vector<ll> T(n);
  for (ll i = 0; i < n; i++) cin >> T[i];
  ll cnt = 0;

  for (ll i = 0; i < n; i++) {
    if (i == 0) {
      if (T[a + i]) cnt++;
    }else if (a - i >= 0 && a + i < n) {
      if (T[a - i] && T[a + i]) cnt += 2;
    }else if (a - i >= 0) {
      if (T[a - i]) cnt++;
    }else if (a + i < n) {
      if (T[a + i]) cnt++;
    }else break;

  }
  cout << cnt << endl;


  return 0;
}

