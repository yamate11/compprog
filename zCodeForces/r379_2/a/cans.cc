#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  string s; cin >> s;
  ll a = 0;
  for (ll i = 0; i < n; i++) if (s[i] == 'A') a++;
  ll d = n - a;
  string ans = a == d ? "Friendship" : a > d ? "Anton" : "Danik";
  cout << ans << endl;

  return 0;
}

