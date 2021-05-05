#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

ll func(ll n) {
  ll ans = 1;
  while (n > 0) {
    ll z = n % 10;
    ans *= z;
    n /= 10;
  }
  return ans;
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, B; cin >> N >> B;

  ll ans = 0;
  ll t2 = 1;
  while (true) {
    ll t3 = t2;
    while (true) {
      ll t5 = t3;
      while (true) {
        ll t7 = t5;
        while (true) {
          if (func(t7 + B) == t7) ans++;
          t7 *= 7;
          if (t7 + B > N) break;
        }
        t5 *= 5;
        if (t5 + B > N) break;
      }
      t3 *= 3;
      if (t3 + B > N) break;
    }
    t2 *= 2;
    if (t2 + B > N) break;
  }

  if (B <= N && func(B) == 0) ans++;

  cout << ans << endl;

  return 0;
}

