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

  ll N, M; cin >> N >> M;
  using sta = pair<ll, ll>;
  vector<sta> CA;
  for (ll i = 0; i < M; i++) {
    ll a, c; cin >> a >> c;
    CA.emplace_back(c, a);
  }
  sort(CA.begin(), CA.end());
  ll rem = N;
  ll cost = 0;
  for (ll i = 0; i < M && rem > 1; i++) {
    auto [c, a] = CA[i];
    ll newRem = gcd(a, rem);
    cost += (rem - newRem) * c;
    rem = newRem;
  }
  if (rem == 1) cout << cost << endl;
  else cout << -1 << endl;
  

  return 0;
}

