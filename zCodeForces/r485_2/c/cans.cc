#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  const ll big = 1e15;
  ll n; cin >> n;
  vector<ll> S(n + 1), C(n + 1);
  for (ll i = 1; i <= n; i++) cin >> S[i];
  for (ll i = 1; i <= n; i++) cin >> C[i];
  vector<ll> cost1(n + 1);
  map<ll, ll> mp1;
  mp1[0] = big;
  for (ll i = 1; i <= n; i++) {
    auto it = mp1.lower_bound(S[i]);
    it--;
    cost1[i] = it->second;
    if (it->second > C[i]) {
      it++;
      while (it != mp1.end() && it->second >= C[i]) it = mp1.erase(it);
      mp1[S[i]] = C[i];
    }
  };
  vector<ll> cost2(n + 1);
  map<ll, ll>mp2;
  mp2[ll(1e10)] = big;
  for (ll i = n; i >= 1; i--) {
    auto it = mp2.upper_bound(S[i]);
    cost2[i] = it->second;
    if (it->second > C[i]) {
      while (true) {
        if (it == mp2.begin()) break;
        it--;
        if (!(it->second >= C[i])) break;
        it = mp2.erase(it);
      }
      mp2[S[i]] = C[i];
    }
  }

  ll ans = big;
  for (ll i = 1; i <= n; i++) {
    ans = min(ans, C[i] + cost1[i] + cost2[i]);
  }
  if (ans >= big) {
    cout << -1 << endl;
  }else {
    cout << ans << endl;
  }
  
  return 0;
}

