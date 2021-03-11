#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, t, k; cin >> n >> t >> k;
  vector<ll> A(n);
  for (ll i = 0; i < n; i++) cin >> A[i];
  ll minLeaf = A[n - 1];
  for (ll i = 0; i < n - 1; i++) minLeaf += max(0LL, A[i] - A[i + 1]);
  ll maxLeaf = (n - 1) - (t - 1);
  if (!(minLeaf <= k && k <= maxLeaf)) {
    cout << -1 << endl;
    return 0;
  }
  cout << n << endl;
  ll rem = maxLeaf - k;
  ll p_main = 1;
  ll c_main = 2;
  for (ll i = 0; i < t; i++) {
    cout << p_main << " " << c_main << "\n";
    for (ll r = 1; r < A[i]; r++) {
      ll x = c_main + r;
      ll p;
      if (rem > 0 && i - 1 >= 0 && r < A[i - 1]) {
	p = p_main + r;
	rem--;
      }else {
	p = p_main;
      }
      cout << p << " " << x << "\n";
    }
    p_main = c_main;
    c_main += A[i];
  }
    


  return 0;
}

