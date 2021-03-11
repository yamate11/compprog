#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  map<ll, bool> mp;
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    if (mp[a]) {
      cout << "NO\n";
      return 0;
    }
    mp[a] = true;
  }
  cout << "YES\n";

  return 0;
}

