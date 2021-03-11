#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  ll M = 63;
  vector v(M, vector<ll>(N));
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a; a--;
    v.at(0).at(i) = a;
  }
  for (ll k = 0; k < M-1; k++) {
    for (ll i = 0; i < N; i++) {
      v.at(k+1).at(i) = v.at(k).at(v.at(k).at(i));
    }
  }

  ll i = 0;
  for (ll k = M-1; k >= 0; k--) {
    ll b = 1LL << k;
    if ((b & K) != 0) i = v.at(k).at(i);
  }
  cout << i + 1 << endl;

  return 0;
}

