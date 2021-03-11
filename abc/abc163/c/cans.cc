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
  vector<ll> V(N+1);
  for (ll i = 2; i <= N; i++) {
    ll a; cin >> a;
    V.at(a)++;
  }
  for (ll i = 1; i <= N; i++) {
    cout << V.at(i) << "\n";
  }

  return 0;
}

