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

  ll N, K; cin >> N >> K;
  vector<ll> vec;
  for (ll i = 0; i < N; i++) {
    ll a, b; cin >> a >> b;
    vec.push_back(b);
    vec.push_back(a - b);
  }
  sort(vec.begin(), vec.end(), greater<ll>());
  ll ans = 0;
  for (ll k = 0; k < K; k++) ans += vec[k];
  cout << ans << endl;

  return 0;
}

