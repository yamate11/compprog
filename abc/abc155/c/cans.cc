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
  ll vmax = 0;
  map<string, ll> mp;
  for (ll i = 0; i < N; i++) {
    string s; cin >> s;
    ll cnt = ++mp[s];
    if (vmax < cnt) vmax = cnt;
  }
  vector<string> ss;
  for (auto p : mp) {
    if (p.second == vmax) ss.push_back(p.first);
  }
  sort(ss.begin(), ss.end());
  for (string s : ss) {
    cout << s << "\n";
  }

  return 0;
}

