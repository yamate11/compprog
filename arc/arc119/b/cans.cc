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
  string S, T; cin >> S >> T;
  ll cntS = 0, cntT = 0;
  for (ll i = 0; i < N; i++) {
    if (S[i] == '1') cntS++;
    if (T[i] == '1') cntT++;
  }
  if (cntS != cntT) {
    cout << -1 << endl;
    return 0;
  }
  ll ans = 0;
  ll i = 0;
  for (; i < N; ) {
    if (S[i] == T[i]) {
      i++;
      continue;
    }
    ll zS = 0, zT = 0;
    ll j = 0;
    while (true) {
      if (S[i + j] == '0') zS++;
      if (T[i + j] == '0') zT++;
      j++;
      if (zS == zT) break;
    }
    ans += zS;
    i += j;
  }
  cout << ans << endl;


  return 0;
}

