#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  map<char, int> mp;
  for (ll i = 0; i < 10; i++) mp['0' + i] = i;
  mp['O'] = 0;
  mp['D'] = 0;
  mp['I'] = 1;
  mp['Z'] = 2;
  mp['S'] = 5;
  mp['B'] = 8;

  string S; cin >> S;
  ll ans = 0;
  for (ll i = 0; i < (ll)S.size(); i++) {
    ans = ans * 10 + mp[S.at(i)];
  }
  cout << ans << endl;

  return 0;
}

