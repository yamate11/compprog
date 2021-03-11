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
  vector<bool> vec((ll)2e5 + 10);
  for (ll i = 0; i < N; i++) {
    ll p; cin >> p;
    vec[p] = true;
    while (vec[ans]) ans++;
    cout << ans << "\n";
  }

  return 0;
}

