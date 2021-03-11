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
  map<string, ll> mp;
  for (ll i = 0; i < N; i++) {
    string s; cin >> s;
    mp[s]++;
  }
  ll vmax = 0;
  string ans;
  for (auto x : mp) {
    if (vmax < x.second) {
      vmax = x.second;
      ans = x.first;
    }
  }
  cout << ans << endl;

  return 0;
}

