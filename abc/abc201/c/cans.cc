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

  string S; cin >> S;

  ll cnt = 0;
  for (ll i = 0; i < 10000; i++) {
    vector<ll> A(4);
    A[3] = i % 10;
    ll x = i / 10;
    A[2] = x % 10;
    x = x / 10;
    A[1] = x % 10;
    A[0] = x / 10;
    vector<bool> c(10);
    for (ll j = 0; j < 4; j++) {
      c[A[j]] = true;
    }
    bool succ = true;
    for (ll j = 0; j < 10; j++) {
      if (S[j] == 'o' && !c[j]) {
        succ = false;
        break;
      }else if (S[j] == 'x' && c[j]) {
        succ = false;
        break;
      }
    }
    if (succ) cnt++;
  }
  cout << cnt << endl;

  return 0;
}

