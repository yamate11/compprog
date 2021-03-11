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

  ll N, S, D; cin >> N >> S >> D;
  bool ok = false;
  for (ll i = 0; i < N; i++) {
    ll X, Y; cin >> X >> Y;
    if (X >= S || Y <= D) continue;
    ok = true;
  }
  cout << (ok ? "Yes\n" : "No\n") ;

  return 0;
}

