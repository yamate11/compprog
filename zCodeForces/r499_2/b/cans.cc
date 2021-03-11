#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m; cin >> n >> m;
  vector<ll> A(m);
  for (ll i = 0; i < m; i++) cin >> A[i];
  vector<ll> num(101);
  for (ll i = 0; i < m; i++) num[A[i]]++;
  for (ll d = 1; d < 1000; d++) {
    ll cnt = 0;
    for (ll i = 1; i <= 100; i++) {
      cnt += num[i] / d;
    }
    if (cnt < n) {
      cout << d - 1 << endl;
      return 0;
    }
  }


  return 0;
}

