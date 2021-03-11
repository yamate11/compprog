#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto check = [&](ll K, auto& vec) -> ll {
    ll sz = vec.size();
    vec.resize(sz * 2);
    for (ll i = 0; i < sz; i++) vec[sz + i] = vec[i];
    vector<ll> acc(sz * 2 + 1);
    for (ll i = 0; i < sz * 2; i++) acc[i + 1] = acc[i] + vec[i];
    ll ans = vec[0];
    for (ll i = 0; i < sz; i++) {
      for (ll d = 1; d <= min(sz, K); d++) {
	ll val = acc[i + d] - acc[i];
	updMax(ans, val);
	updMax(ans, val + acc[sz] * ((K - d) / sz));
      }
    }
    return ans;
  };

  ll N, K; cin >> N >> K;
  vector<ll> P(N), C(N);
  vector<bool> done(N);
  for (ll i = 0; i < N; i++) {
    ll p; cin >> p; p--;
    P[i] = p;
  }
  for (ll i = 0; i < N; i++) cin >> C[i];

  ll ans = LLONG_MIN;
  for (ll i = 0; i < N; i++) {
    if (done[i]) continue;
    done[i] = true;
    vector<ll> vec;
    vec.push_back(C[i]);
    for (ll j = P[i]; j != i; j = P[j]) {
      done[j] = true;
      vec.push_back(C[j]);
    }
    ll val = check(K, vec);
    ans = max(ans, val);
  }
  cout << ans << endl;

  return 0;
}

