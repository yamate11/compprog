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
  
  double sum = 0;
  for (ll c = 1; c <= N; c++) {
    ll t = 1;
    while (t * c < K) t *= 2;
    sum += 1.0 / t;
  }
  cout << sum / N << endl;

  return 0;
}

