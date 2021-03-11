#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  using sta = pair<ll, ll>;
  vector<sta> rec;
  map<ll, ll> mp;
  mp[0] = 0;
  ll sum = 0;
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    sum += a;
    auto it = mp.find(sum);
    if (it == mp.end()) {
      mp[sum] = i + 1;
    }else {
      ll prev = it->second;
      rec.emplace_back(i, prev);
      it->second = i + 1;
    }
  }
  sort(rec.begin(), rec.end());
  ll bnd = -1;
  ll cnt = 0;
  for (auto [r, l] : rec) {
    if (l < bnd) continue;
    cnt++;
    bnd = r;
  }
  cout << cnt << endl;

  


  return 0;
}

