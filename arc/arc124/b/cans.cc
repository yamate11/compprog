#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N), B(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  for (ll i = 0; i < N; i++) cin >> B[i];
  sort(B.begin(), B.end());
  multiset<ll> borig;
  for (ll i = 0; i < N; i++) borig.insert(B[i]);
  vector<ll> ans;
  for (ll i = 0; i < N; i++) {
    if (i > 0 && B[i - 1] == B[i]) continue;
    auto bs = borig;
    ll x = A[0] ^ B[i];
    {
      auto it = bs.find(B[i]);
      bs.erase(it);
    }
    bool succ = true;
    for (ll j = 1; j < N; j++) {
      ll y = x ^ A[j];
      auto it = bs.find(y);
      if (it == bs.end()) {
        succ = false;
        break;
      }
      bs.erase(it);
    }
    if (succ) ans.push_back(x);
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for (ll a : ans) cout << a << "\n";

  return 0;
}

