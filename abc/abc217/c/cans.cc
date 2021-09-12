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

  ll N; cin >> N;
  vector<ll> Q(N);
  for (ll i = 0; i < N; i++) {
    ll p; cin >> p; p--;
    Q[p] = i + 1;
  }
  for (ll i = 0; i < N; i++) {
    cout << Q[i] << " ";
  }
  cout << endl;

  return 0;
}

