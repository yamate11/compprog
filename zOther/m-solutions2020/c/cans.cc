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
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A.at(i);
  for (ll i = K; i < N; i++) {
    if (A.at(i - K) < A.at(i)) cout << "Yes\n";
    else cout << "No\n";
  }
  

  return 0;
}

