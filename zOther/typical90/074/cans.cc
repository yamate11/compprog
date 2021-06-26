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
  string S; cin >> S;
  ll ans = 0;
  ll p = 1;
  for (ll i = 0; i < N; i++) {
    if (S[i] == 'b') ans += p;
    else if (S[i] == 'c') ans += 2 * p;
    p *= 2;
  }
  cout << ans << endl;
  return 0;
}

