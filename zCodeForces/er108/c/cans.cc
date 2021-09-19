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
    vector<ll> U(N), S(N);
    for (ll i = 0; i < N; i++) {
      cin >> U[i];
      U[i]--;
    }
    for (ll i = 0; i < N; i++) cin >> S[i];
    vector<vector<ll>> A(N);
    for (ll i = 0; i < N; i++) A[U[i]].push_back(S[i]);
    sort(A.begin(), A.end(),
         [&](auto& x, auto& y) -> bool {
           return x.size() > y.size();
         });
    vector<vector<ll>> T(N);
    for (ll i = 0; i < N; i++) {
      ll sz = A[i].size();
      if (sz == 0) break;
      sort(A[i].begin(), A[i].end());
      T[i].resize(sz + 1);
      for (ll j = 0; j < sz; j++) T[i][j + 1] = T[i][j] + A[i][j];
    }
    vector<ll> ans(N + 1);
    for (ll k = 1; k <= N; k++) {
      for (ll i = 0; i < N; i++) {
        ll sz = A[i].size();
        if (sz / k == 0) break;
        ans[k] += T[i][sz] - T[i][sz % k];
      }
    }
    for (ll k = 1; k <= N; k++) {
      cout << ans[k] << " ";
    }
    cout << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

