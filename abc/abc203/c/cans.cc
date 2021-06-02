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

  ll N, K; cin >> N >> K;
  using sta = pair<ll, ll>;
  vector<sta> AB;
  for (ll i = 0; i < N; i++) {
    ll a, b; cin >> a >> b;
    AB.emplace_back(a, b);
  }
  sort(AB.begin(), AB.end());
  ll x = K;
  ll p = 0;
  ll idx = 0;
  while (idx < (ll)AB.size()) {
    auto [a, b] = AB[idx];
    if (p + x < a) {
      cout << p + x << endl;
      return 0;
    }
    x -= (a - p);
    p = a;
    x += b;
    idx++;
  }
  cout << p + x << endl;
  

  return 0;
}

