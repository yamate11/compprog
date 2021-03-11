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

  using sta = pair<ll, ll>;
  vector<sta> ans;
  

  auto solve = [&]() -> bool {
    
    ll N; cin >> N;
    vector<ll> A(N + 1), B(N + 1), P(N + 1), revP(N + 1);
    using stb = pair<ll, ll>;
    vector<stb> AI(N + 1);

    for (ll i = 1; i <= N; i++) {
      ll a; cin >> a;
      A[i] = a;
      AI[i] = stb(a, i);
    }
    sort(AI.begin(), AI.end());
    for (ll i = 1; i <= N; i++) cin >> B[i];
    for (ll i = 1; i <= N; i++) {
      ll p; cin >> p;
      P[i] = p;
      revP[p] = i;
    }
    for (ll i = 1; i <= N; i++) {
      ll j = P[i];
      if (i != j && B[j] >= A[i]) return false;
    }
    for (auto [a, i] : AI) {
      ll j = revP[i];
      if (i == j) continue;
      ans.emplace_back(i, j);
      P[j] = P[i];
      revP[P[i]] = j;
    }
    return true;
  };

  if (!solve()) {
    cout << -1 << endl;
    return 0;
  }
  cout << ans.size() << endl;
  for (auto [i, j] : ans) {
    cout << i << " " << j << "\n";
  }
  

  return 0;
}

