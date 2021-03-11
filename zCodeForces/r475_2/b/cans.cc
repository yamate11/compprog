#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, A, B, C, T; cin >> n >> A >> B >> C >> T;
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    ll v; cin >> v;
    if (B >= C) {
      ans += A;
    }else {
      ans += A + (C - B) * (T - v);
    }
  }
  cout << ans << endl;

  return 0;
}

