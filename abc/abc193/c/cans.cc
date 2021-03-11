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
  ll lim = llround(sqrt(N)) + 10;
  vector<bool> rec(lim);
  ll cnt = 0;
  for (ll i = 2; i < lim; i++) {
    if (rec[i]) continue;
    ll x = i * i;
    for (ll j = 2; x <= N; j++) {
      if (x < lim) rec[x] = true;
      x *= i;
      cnt++;
    }
  }
  cout << N - cnt << endl;

  return 0;
}

