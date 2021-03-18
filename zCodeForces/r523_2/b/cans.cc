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
  vector<ll> A(n);
  ll s = 0;
  ll vm = 0;
  for (ll i = 0; i < n; i++) {
    ll a; cin >> a;
    A[i] = a;
    s += a;
    vm = max(vm, a);
  }
  sort(A.begin(), A.end(), greater<ll>());
  A.push_back(0);
  ll t = 0;
  for (ll i = 0; i < n; i++) {
    t++;
    ll rem = vm - t;
    if (A[i + 1] < rem) {
      t += rem - A[i + 1];
    }
  }
  cout << s - t << endl;


  return 0;
}

