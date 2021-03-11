#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, k; cin >> n >> k;
  vector<char> disp(n);
  for (ll i = 0; i < n; i++) {
    ll x = 0;
    for (ll j = 0; j < 7; j++) {
      char c; cin >> c;
      x << 1;
      x |= (c == '0' ? 0 : 1);
    }
    disp.at(i) = x;
  }

  return 0;
}

