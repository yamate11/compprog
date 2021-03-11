#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll K, N; cin >> K >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A.at(i);
  ll vmax = 0;
  for (ll i = 0; i < N; i++) {
    ll d = (K + A.at((i+1) % N) - A.at(i)) % K;
    vmax = max(vmax, d);
  }
  cout << K - vmax << endl;

  return 0;
}

