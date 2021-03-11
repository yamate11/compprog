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
  vector<bool> on(n + 1);
  ll vmax = 0;
  ll cur = 0;
  for (ll i = 0; i < 2 * n; i++) {
    ll x; cin >> x;
    if (on[x]) {
      cur--;
    }else {
      on[x] = true;
      cur++;
    }
    vmax = max(vmax, cur);
  }
  cout << vmax << endl;


  return 0;
}

