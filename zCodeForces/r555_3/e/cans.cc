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
  vector<ll> A(n), vec(n);
  set<ll> bs;
  for (ll i = 0; i < n; i++) cin >> A[i];
  for (ll i = 0; i < n; i++) {
    ll b; cin >> b;
    if (vec[b] == 0) bs.insert(b);
    vec[b]++;
  }
  for (ll i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    ll x = n - A[i];
    auto it = bs.lower_bound(x);
    if (it == bs.end()) {
      it = bs.begin();
    }
    ll y = *it;
    cout << (A[i] + y) % n;
    vec[y]--;
    if (vec[y] == 0) bs.erase(it);
  }
  cout << endl;

  return 0;
}

