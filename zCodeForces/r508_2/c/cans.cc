#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  using sta = pair<ll, ll>;
  vector<sta> vec;
  for (ll i = 0; i < n; i++) {
    ll a; cin >> a;
    vec.emplace_back(a, 0);
  }
  for (ll i = 0; i < n; i++) {
    ll a; cin >> a;
    vec.emplace_back(a, 1);
  }
  sort(vec.begin(), vec.end());
  ll ma = 0;
  ll mb = 0;
  for (ll i = 0; i < n; i++) {
    auto [x, p] = vec.back();
    vec.pop_back();
    auto [y, q] = vec.back();
    vec.pop_back();
    if (p == 0) ma += x;
    if (q == 1) mb += y;
  }
  cout << ma - mb << endl;


  return 0;
}

