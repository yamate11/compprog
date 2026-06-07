#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  using vec_t = pair<ll, ll>;
  vector<vec_t> vec;
  
  ll n; cin >> n;
  for (ll i = 0; i < n; i++) {
    ll x; cin >> x;
    vec.emplace_back(x, i);
  }
  sort(vec.begin(), vec.end());
  vector<bool> seen(n);
  vector<vector<ll>> ans;
  for (ll i = 0; i < n; i++) {
    if (seen[i]) continue;
    ll j = i;
    vector<ll> vv;
    while (!seen[j]) {
      seen[j] = true;
      vv.push_back(j);
      auto [x, p] = vec[j];
      j = p;
    };
    ans.push_back(move(vv));
  }
  cout << ans.size() << endl;
  for (const auto& v : ans) {
    cout << v.size();
    for (ll p : v) {
      cout << " " << p + 1;
    }
    cout << "\n";
  }

  return 0;
}

