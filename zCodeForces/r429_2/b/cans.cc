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
  bool b = false;
  for (ll i = 0; i < n; i++) {
    ll a; cin >> a;
    if (a % 2 == 1) b = true;
  }
  cout << (b ? "First" : "Second") << endl;


  return 0;
}

