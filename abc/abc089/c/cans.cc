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
  map<char, ll> mp;
  for (ll i = 0; i < N; i++) {
    string s; cin >> s;
    mp[s.at(0)]++;
  }
  string march = "MARCH";
  ll cnt = 0;
  for (ll i = 0; i < 5; i++) {
    for (ll j = i + 1; j < 5; j++) {
      for (ll k = j + 1 ; k < 5; k++) {
	cnt += mp[march.at(i)] * mp[march.at(j)] * mp[march.at(k)];
      }
    }
  }
  cout << cnt << endl;

  return 0;
}

