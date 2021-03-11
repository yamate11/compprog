#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll L, R; cin >> L >> R;
  vector<ll> sl(41), sr(41);
  for (ll i = 0; i < L; i++) {
    ll x; cin >> x;
    sl.at(x)++;
  }
  for (ll i = 0; i < R; i++) {
    ll x; cin >> x;
    sr.at(x)++;
  }
  ll tot = 0;
  for (ll i = 10; i <= 40; i++) {
    tot += min(sl.at(i), sr.at(i));
  }
  cout << tot << endl;

  return 0;
}

