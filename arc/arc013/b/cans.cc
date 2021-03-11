#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll C; cin >> C;
  vector<ll> m(3);
  vector<ll> v(3);
  for (ll i = 0; i < C; i++) {
    for (ll j = 0; j < 3; j++) cin >> v.at(j);
    sort(v.begin(), v.end());
    for (ll j = 0; j < 3; j++) m.at(j) = max(m.at(j), v.at(j));
  }
  cout << m.at(0) * m.at(1) * m.at(2) << endl;

  return 0;
}

