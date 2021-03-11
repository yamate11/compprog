#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    ll m; cin >> m;
    if (m < 80) ans += 80 - m;
  }
  cout << ans << endl;

  return 0;
}

