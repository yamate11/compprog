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

  vector A(11, 0LL);
  A[0] = 1;
  for (ll i = 1; i <= 10; i++) A[i] = i * A[i-1];
  ll P; cin >> P;
  ll cnt = 0;
  for (ll i = 10; i >= 1; i--) {
    ll x = P / A[i];
    cnt += x;
    P = P % A[i];
  }
  cout << cnt << endl;

  return 0;
}

