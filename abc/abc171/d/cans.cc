#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  map<ll, ll> mp;
  ll N; cin >> N;
  ll s = 0;
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    s += a;
    mp[a]++;
  }
  ll Q; cin >> Q;
  for (ll _q = 0; _q < Q; _q++) {
    ll b, c; cin >> b >> c;
    s += (c - b) * mp[b];
    mp[c] += mp[b];
    mp[b] = 0;
    cout << s << "\n";
  }

  return 0;
}

