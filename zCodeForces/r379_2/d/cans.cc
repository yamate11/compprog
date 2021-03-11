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
  ll x0, y0; cin >> x0 >> y0;

  vector<bool> veff(8, false);
  vector<ll> vdist(8, 1e10);
  for (ll i = 0; i < n; i++) {
    char c; ll x,y; cin >> c >> x >> y;
    x -= x0;
    y -= y0;
    ll d = -1;
    ll idx = -1;
    bool eff = false;
    if (x == 0) {
      eff = (c == 'R' || c == 'Q');
      if (y > 0) {idx = 2; d = y; }
      else       {idx = 6; d = -y; }
    }else if (y == 0) {
      eff = (c == 'R' || c == 'Q');
      if (x > 0) { idx = 0; d = x; }
      else       { idx = 4; d = -x; }
    }else if (x == y) {
      eff = (c == 'B' || c == 'Q');
      if (x > 0) { idx = 1; d = x; }
      else       { idx = 5; d = -x; }
    }else if (x + y == 0) {
      eff = (c == 'B' || c == 'Q');
      if (y > 0) { idx = 3; d = y; }
      else       { idx = 7; d = x; }
    }else {
      continue;
    }
    if (d < vdist[idx]) {
      vdist[idx] = d;
      veff[idx] = eff;
    }
  }
  for (ll i = 0; i < 8; i++) {
    if (veff[i]) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";

  return 0;
}

