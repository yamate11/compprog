#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

#define repFT(x, from, to) for (ll x = (from); x < (to); x++)
#define rep(x,y)  repFT(x, 0, y)

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  const ll lim = 5010;
  auto S = vector(lim, vector(lim, 0LL));
  rep(i, N) {
    ll a, b; cin >> a >> b;
    S[a][b]++;
  }
  repFT(i, 1, lim) repFT(j, 1, lim) S[i][j] += S[i-1][j];
  repFT(i, 1, lim) repFT(j, 1, lim) S[i][j] += S[i][j-1];
  ll ans = 0;
  rep(i, lim - (K+1)) rep(j, lim - (K+1)) {
    ll s = S[i+K+1][j+K+1] - S[i][j+K+1] - S[i+K+1][j] + S[i][j];
    ans = max(ans, s);
  }
  cout << ans << endl;
  return 0;
}

