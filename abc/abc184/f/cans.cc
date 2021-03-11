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

  ll N, T; cin >> N >> T;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  ll n2 = N / 2;
  ll m2 = N - n2;
  vector<ll> vec1, vec2;
  for (ll i = 0; i < (1 << n2); i++) {
    ll s = 0;
    for (ll j = 0; j < n2; j++) {
      if ((i >> j) & 1) s += A[j];
    }
    vec1.push_back(s);
  }
  for (ll i = 0; i < (1 << m2); i++) {
    ll s = 0;
    for (ll j = 0; j < m2; j++) {
      if ((i >> j) & 1) s += A[n2 + j];
    }
    vec2.push_back(s);
  }
  sort(vec2.begin(), vec2.end());
  ll ans = 0;
  for (ll x : vec1) {
    if (x == T) {
      cout << T << endl;
      return 0;
    }
    if (x > T) continue;
    auto it = upper_bound(vec2.begin(), vec2.end(), T - x);
    auto rit = reverse_iterator(it);
    ans = max(ans, *rit + x);
  }
  cout << ans << endl;

  return 0;
}

