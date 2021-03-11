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
  bool first = true;
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    if (a == X) continue;
    if (first) first = false;
    else cout << " ";
    cout << a;
  }
  cout << endl;

  return 0;
}

