#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, k; cin >> n >> k;
  string s; cin >> s;
  vector<ll> cnt(128);
  for (ll i = 0; i < n; i++) {
    cnt[s[i]]++;
  }
  ll ans = LLONG_MAX;
  for (ll i = 0; i < k; i++) {
    ans = min(ans, cnt['A' + i]);
  }
  cout << ans * k << endl;

  return 0;
}

