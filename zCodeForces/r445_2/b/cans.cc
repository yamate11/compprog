#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll lim = 2e5;
  ll n; cin >> n;
  vector<ll> A(n);
  for (ll i = 0; i < n; i++) cin >> A[i];
  vector<ll> rec(lim + 1, lim + 100);
  for (ll i = 0; i < n; i++) {
    rec[A[i]] = i;
  }
  auto it = min_element(rec.begin(), rec.end());
  cout << it - rec.begin() << endl;


  return 0;
}

