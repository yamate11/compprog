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

  vector<ll> hidx(128, -1);
  hidx['R'] = 0;
  hidx['S'] = 1;
  hidx['P'] = 2;

  ll N, K; cin >> N >> K;
  string s; cin >> s;
  auto vec = vector(K+1, vector(N, '.'));
  for (ll i = 0; i < N; i++) vec[0][i] = s[i];
  ll dist = 1;
  for (ll k = 1; k <= K; k++) {
    for (ll i = 0; i < N; i++) {
      ll c1 = vec[k-1][i];
      ll c2 = vec[k-1][(i + dist) % N];
      if (hidx[c1] == (hidx[c2] + 1) % 3) {
        vec[k][i] = c2;
      }else {
        vec[k][i] = c1;
      }
    }
    dist = (dist * 2) % N;
  }
  cout << vec[K][0] << endl;

  return 0;
}

