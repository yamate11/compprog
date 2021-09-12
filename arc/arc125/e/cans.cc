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

  ll N, M; cin >> N >> M;
  vector<ll> A(N), B(M), C(M);
  for (ll i = 0; i < N; i++) cin >> A[i];
  sort(A.begin(), A.end());
  for (ll i = 0; i < M; i++) cin >> B[i];
  for (ll i = 0; i < M; i++) cin >> C[i];
  vector<pair<ll, ll>> BC;
  for (ll i = 0; i < M; i++) BC.emplace_back(B[i], C[i]);
  sort(BC.begin(), BC.end(),
       [&](const auto& x, const auto& y) -> bool {
         const auto& [xb, xc] = x;
         const auto& [yb, yc] = y;
         return (double)xc * yb > (double)yc * xb;
       });
  vector<ll> accB(M + 1), accC(M + 1);
  for (ll i = 0; i < M; i++) accB[i + 1] = accB[i] + BC[i].first;
  for (ll i = M - 1; i >= 0; i--) accC[i] = accC[i + 1] + BC[i].second;
  
  ll sumA = 0;
  for (ll i = 0; i < N; i++) sumA += A[i];
  ll vmin = sumA;
  ll p = M;
  for (ll t = 1; t <= N; t++) {
    sumA -= A[N - t];
    for (; p > 0; p--) {
      const auto& [b, c] = BC[p-1];
      if (t * b < c) break;
    }
    ll thisv = sumA + t * accB[p] + accC[p];
    vmin = min(vmin, thisv);
  }
  cout << vmin << endl;

  return 0;
}

