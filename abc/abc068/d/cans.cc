#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll K; cin >> K;
  ll N = 50;
  ll m = K / N;
  ll r = K % N;
  ll lev = N-1 + m;
  vector<ll> vec(N, lev);
  for (ll i = 0; i < r; i++) {
    vec.at(i) += N;
    for (ll j = 0; j < N; j++) {
      if (j == i) continue;
      vec.at(j)--;
    }
  }
  cout << N << endl;
  for (ll i = 0; i < N; i++) {
    if (i > 0) cout << " ";
    cout << vec.at(i);
  }
  cout << endl;

  return 0;
}

