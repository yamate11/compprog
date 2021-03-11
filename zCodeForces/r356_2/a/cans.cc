#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<ll> t(5);
  vector<ll> cnt(101);
  ll sum = 0;
  for (ll i = 0; i < 5; i++) {
    ll a; cin >> a;
    t[i] = a;
    cnt[a]++;
    sum += a;
  }
  vector<pair<ll,ll>> vec;
  for (ll i = 0; i < 101; i++) {
    if (cnt[i] > 0) vec.emplace_back(cnt[i], i);
  }
  sort(vec.begin(), vec.end(), greater<pair<ll,ll>>());
  if (vec[0].first >= 4) {
    cout << sum - 3 * vec[0].second << endl;
  }else if (vec[0].first == 3) {
    if (vec[1].first == 2) {
      ll z = max(vec[0].second * 3, vec[1].second * 2);
      cout << sum - z << endl;
    }else {
      cout << sum - 3 * vec[0].second << endl;
    }
  }else if (vec[0].first == 2) {
    if (vec[1].first == 2) {
      ll z = max(vec[0].second * 2, vec[1].second * 2);
      cout << sum - z << endl;
    }else {
      cout << sum - 2 * vec[0].second << endl;
    }
  }else {
    cout << sum << endl;
  }

  return 0;
}

