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
  const ll ORIG = 2;
  const ll REV = 3;
  vector<ll> vec(10, ORIG);
  for (ll i = 0; i < n; i++) {
    char op; ll arg; cin >> op >> arg;
    for (ll j = 0; j < 10; j++) {
      ll bit = (arg >> j) & 1;
      if (op == '|') {
        if (bit) vec[j] = 1;
      }else if (op == '&') {
        if (!bit) vec[j] = 0;
      }else if (op == '^') {
        if (bit) vec[j] = vec[j] ^ 1;
      }
    }
  }
  vector ans(4, 0LL);
  for (ll x = 0; x <= 3; x++) {
    for (ll j = 0; j < 10; j++) {
      if (vec[j] == x) ans[x] = (ans[x] | (1LL << j));
    }
  }

  ll mask = ((1LL << 10) - 1);

  cout << 3 << endl;
  cout << "^ " << ans[REV] << endl;
  cout << "& " << (ans[0] ^ mask) << endl;
  cout << "| " << ans[1] << endl;
    

  return 0;
}

