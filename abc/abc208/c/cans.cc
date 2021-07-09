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

  ll N, K; cin >> N >> K;
  using sta = pair<ll, ll>;
  vector<bool> small(N);
  vector<sta> A;
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    A.emplace_back(a, i);
  }
  sort(A.begin(), A.end());
  for (ll i = 0; i < K % N; i++) {
    auto [a, j] = A[i];
    small[j] = true;
  }
  for (ll i = 0; i < N; i++) {
    if (small[i]) {
      cout << (K / N) + 1 << "\n";
    }else {
      cout << (K / N) << "\n";
    }
  }
  

  return 0;
}

