#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll N; cin >> N;
    vector<ll> A(N), L(N);
    for (ll i = 0; i < N; i++) cin >> A[i];
    vector<ll> ul;
    for (ll i = 0; i < N; i++) {
      ll l; cin >> l;
      L[i] = l;
      if (l == 0) ul.push_back(A[i]);
    }
    sort(ul.begin(), ul.end(), greater<ll>());
    ll j = 0;
    for (ll i = 0; i < N; i++) {
      if (L[i] == 0) A[i] = ul[j++];
    }
    for (ll i = 0; i < N; i++) {
      if (i > 0) cout << " ";
      cout << A[i];
    }
    cout << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

