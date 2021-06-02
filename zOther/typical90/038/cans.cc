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

  ll A, B; cin >> A >> B;
  const ll lim = 1'000'000'000'000'000'000;
  ll g = gcd(A, B);
  A /= g;
  B /= g;
  ll x = A;
  if (B > lim / x) {
    cout << "Large\n";
    return 0;
  }
  x *= B;
  if (g > lim / x) {
    cout << "Large\n";
    return 0;
  }
  x *= g;
  cout << x << endl;
  
  

  return 0;
}

