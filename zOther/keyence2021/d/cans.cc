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
  
  ll K = (1LL << N) - 1;
  cout << K << "\n";
  for (ll x = 1; x <= K; x++) {
    for (ll t = 0; t < (1 << N); t++) {
      ll y = x & t;
      ll z = __builtin_popcountll(y) % 2;
      if (z == 0) cout << "A";
      else cout << "B";
    }
    cout << "\n";
  }



  return 0;
}

