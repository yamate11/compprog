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
  ll cnt = 0;
  ll thr = 1000;
  if (N <= 999) {
    cout << 0 << endl;
    return 0;
  }
  for (ll i = 1; true; i++) {
    if (N >= 1000 * thr) cnt += i * (thr * 1000 - thr);
    else {
      cnt += i * (N - thr + 1);
      break;
    }
    thr *= 1000;
  }
  cout << cnt << endl;

  return 0;
}

