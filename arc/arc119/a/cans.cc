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
  ll a = N;
  ll b = 0;
  ll c = 0;
  ll ans = N;
  ll powb = 1;
  while (true) {
    if (a % 2 == 1) {
      c += powb;
    }
    a /= 2;
    b++;
    powb *= 2;
    ans = min(ans, a + b + c);
    if (a == 0) break;
  }
  cout << ans << endl;
  

  return 0;
}

