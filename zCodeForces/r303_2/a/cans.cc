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
  vector<ll> ans;
  for (ll i = 0; i < n; i++) {
    bool ok = true;
    for (ll j = 0; j < n; j++) {
      ll a; cin >> a;
      if (j == i) continue;
      if (a & 1) {
	ok = false;
      }
    }
    if (ok) ans.push_back(i);
  }
  cout << ans.size() << endl;
  if ((ll)ans.size() > 0) {
    for (ll i = 0; i < (ll)ans.size(); i++) {
      if (i > 0) cout << " ";
      cout << ans[i] + 1;
    }
    cout << endl;
  }

  return 0;
}

