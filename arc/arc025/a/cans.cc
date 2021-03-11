#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<ll> D(7), J(7);
  for (ll i = 0; i < 7; i++) cin >> D.at(i);
  for (ll i = 0; i < 7; i++) cin >> J.at(i);
  ll tot = 0;
  for (ll i = 0; i < 7; i++) tot += max(D.at(i), J.at(i));
  cout << tot << endl;

  return 0;
}

