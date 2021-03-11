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

  ll N, M, A, B; cin >> N >> M >> A >> B;
  ll x = N;
  for (ll i = 0; i < M; i++) {
    if (x <= A) x += B;
    ll c; cin >> c;
    x -= c;
    if (x < 0) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << "complete\n";

  return 0;
}

