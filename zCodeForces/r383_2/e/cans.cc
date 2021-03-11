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
  vector<ll> C(2*n), P(n), F(2*n);
  for (ll i = 0; i < n; i++) {
    ll a, b; cin >> a >> b; a--; b--;
    P[i] = a;
    C[a] = b;
    C[b] = a;
  }
  for (ll i = 0; i < 2*n; i++) {
    ll p = i;
    while (F[p] == 0) {
      F[p] = 1;
      F[C[p]] = 2;
      if (C[p] % 2 == 1) p = C[p] - 1;
      else               p = C[p] + 1;
    }
  }
  for (ll i = 0; i < n; i++) {
    ll p = P[i];
    cout << F[p] << " " << F[C[p]] << "\n";
  }

  return 0;
}

