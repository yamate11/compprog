#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll t; cin >> t;
  for (ll z = 0; z < t; z++) {
    ll n; cin >> n;
    string s; cin >> s;
    ll a = 0;
    while (a < n && s.at(a) == '0') a++;
    ll b = n;
    while (b-1 >= 0 && s.at(b-1) == '1') b--;
    for (ll i = 0; i < a; i++) cout << '0';
    if (a < b) cout << '0';
    for (ll i = b; i < n; i++) cout << '1';
    cout << "\n";
  }


  return 0;
}

