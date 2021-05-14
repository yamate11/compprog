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
  vector<ll> res(200);
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    res[a % 200] ++;
  }
  ll cnt = 0;
  for (ll i = 0; i < 200; i++) {
    cnt += res[i] * (res[i] - 1) / 2;
  }
  cout << cnt << endl;

  return 0;
}

