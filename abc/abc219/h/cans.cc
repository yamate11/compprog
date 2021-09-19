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
  using sta = pair<ll, ll>;
  vector<sta> XA(N);
  for (ll i = 0; i < N; i++) {
    ll x, a; cin >> x >> a;
    XA.emplace_back(x, a);
  }
  sort(XA.begin(), XA.end());

  return 0;
}

