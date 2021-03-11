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
  ll x = 1;
  for (ll i = 0 ; i < N; i++) {
    x = min(2 * x, x + K);
  }
  cout << x << endl;
      
  return 0;
}

