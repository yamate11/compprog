#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> pair<ll, ll> {
    ll n; cin >> n;
    vector<ll> A(n);
    for (ll i = 0; i < n; i++) cin >> A[i];
    vector<ll> reged;
    auto reg = [&](ll d) -> bool {
      if (any_of(reged.begin(), reged.end(),
                 [&](ll x){ return x == d; })) return true;
      if (reged.size() == 2) return false;
      reged.push_back(d);
      return true;
    };
    for (ll i = 0; i+1 < n; i++) if (!reg(A[i+1] - A[i])) return {-1, -1};
    if (reged.size() <= 1) return {0, 0};
    else {
      ll m = abs(reged[1] - reged[0]);
      ll c = max(reged[0], reged[1]);
      if (all_of(A.begin(), A.end(), [&](ll x){ return x < m; })) {
        return {m, c};
      }else return {-1, -1};
    }
  };
  ll T; cin >> T;
  for (ll t = 0; t < T; t++) {
    auto [m, d] = solve();
    if (m <= 0) {
      cout << m << endl;
    }else {
      cout << m << " " << d << "\n";
    }
  }

  return 0;
}

