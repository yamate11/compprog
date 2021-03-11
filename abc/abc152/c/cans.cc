#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  ll vmin = LLONG_MAX;
  ll cnt = 0;
  for (ll i = 0; i < N; i++) {
    ll p; cin >> p;
    if (p <= vmin) {
      cnt++;
      vmin = p;
    }
  }
  cout << cnt << endl;

  return 0;
}

