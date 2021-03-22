#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  ll ans = 0;
  for (ll i = 1; true; i++) {
    string s = to_string(i);
    string s2 = s + s;
    ll x = stoll(s2);
    if (x > N) break;
    ans = i;
  }
  cout << ans << endl;

  return 0;
}

