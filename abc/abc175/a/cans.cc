#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  ll ans = 0;
  ll cnt = 0;
  for (ll i = 0; i < 3; i++) {
    if (S[i] == 'R') cnt++;
    else cnt = 0;
    ans = max(ans, cnt);
  }
  cout << ans << endl;

  return 0;
}

