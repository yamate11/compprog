#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  map<ll,ll> mp;
  ll N; cin >> N;
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    if (mp[a] == 0) mp[a] = 1;
    else mp[a] = 0;
  }
  ll cnt = 0;
  for (auto p : mp) {
    ll x, c;
    tie(x, c) = p;
    cnt += c;
  }
  cout << cnt << endl;

  return 0;
}

