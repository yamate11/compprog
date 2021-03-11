#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> vec(N+1);
  for (ll x = 1; x <= N; x++) {
    if (x * x > N) break;
    for (ll y = 1; y <= N; y++) {
      if (x * x + y * y > N) break;
      for (ll z = 1; z <= N; z++) {
	if (x * x + y * y + z * z > N) break;
	ll t = x*x + y*y + z*z + x*y + y*z + z*x;
	if (t <= N) vec.at(t)++;
      }
    }
  }
  for (ll i = 1; i <= N; i++) {
    cout << vec.at(i) << "\n";
  }


  return 0;
}

