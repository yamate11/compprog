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

  ll N, X; cin >> N >> X;
  ll tot = 0;
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    if (i % 2 == 1) a--;
    tot += a;
  }
  if (tot <= X) cout << "Yes\n";
  else cout << "No\n";

  return 0;
}

