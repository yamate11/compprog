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
  ll s = 0;
  ll m = 0;
  for (ll i = 0; i < N; i++) {
    ll d; cin >> d;
    s += d;
    if (d > m) m = d;
  }
  cout << s << endl;
  if (m <= s - m) cout << 0 << endl;
  else            cout << m - (s-m) << endl;

  return 0;
}

