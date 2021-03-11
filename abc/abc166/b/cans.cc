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
  vector<bool> H(N);
  for (ll i = 0; i < K; i++) {
    ll d; cin >> d;
    for (ll j = 0; j < d; j++) {
      ll a; cin >> a; a--;
      H.at(a) = true;
    }
  }
  ll cnt = 0;
  for (ll i = 0; i < N; i++) {
    if (!H.at(i)) cnt++;
  }
  cout << cnt << endl;

  return 0;
}

