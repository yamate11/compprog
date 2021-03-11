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

  ll N, M; cin >> N >> M;
  vector<ll> H(N), W(M);
  for (ll i = 0; i < N; i++) cin >> H[i];
  for (ll i = 0; i < M; i++) cin >> W[i];
  sort(H.begin(), H.end());

  vector<ll> front(N/2 + 1), back(N/2 + 1);
  for (ll i = 0; i < N/2; i++) {
    front[i+1] = front[i] + abs(H[2*i + 1] - H[2*i]);
    back[i+1] = back[i] + abs(H[N-1 - (2*i + 1)] - H[N-1 - 2*i]);
  }
  ll ans = LLONG_MAX;
  for (ll i = 0; i < M; i++) {
    ll idx = lower_bound(H.begin(), H.end(), W[i]) - H.begin();
    ll n0, m0, k0;
    if (idx % 2 == 0) {
      n0 = idx / 2;
      m0 = N/2 - n0;
      k0 = idx;
    }else {
      n0 = (idx - 1) / 2;
      m0 = N/2 - n0;
      k0 = idx - 1;
    }
    ll th = front[n0] + back[m0] + abs(W[i] - H[k0]);
    ans = min(ans, th);
  }
  cout << ans << endl;
  return 0;
}

