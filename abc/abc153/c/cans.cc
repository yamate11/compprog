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
  vector<ll> H(N);
  for (ll i = 0; i < N; i++) cin >> H.at(i);
  sort(H.begin(), H.end(), greater<ll>());
  ll tot = 0;
  for (ll i = K; i < N; i++) tot += H.at(i);
  cout << tot << endl;

  return 0;
}

