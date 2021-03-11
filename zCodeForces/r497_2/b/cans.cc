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
  ll cur = 1e10;
  for (ll i = 0; i < n; i++) {
    ll w, h; cin >> w >> h;
    if (w < h) swap(w, h);
    if (cur >= w) {
      cur = w;
    }else if (cur >= h) {
      cur = h;
    }else {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";

  return 0;
}

