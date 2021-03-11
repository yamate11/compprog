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

  ll N, W; cin >> N >> W;
  using sta = pair<ll, ll>;
  vector<sta> ev;
  for (ll i = 0; i < N; i++) {
    ll s, t, p; cin >> s >> t >> p;
    ev.emplace_back(s, p);
    ev.emplace_back(t, -p);
  }
  sort(ev.begin(), ev.end());
  ll cur = 0;
  for (auto [x, p] : ev) {
    cur += p;
    if (cur > W) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  return 0;
}

