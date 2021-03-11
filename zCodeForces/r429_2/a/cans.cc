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
  for (ll i = 0; i < n; i++) cnt[s[i]]++;
  for (ll c = 'a'; c <= 'z'; c++) {
    if (cnt[c] > k) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;

  return 0;
}

