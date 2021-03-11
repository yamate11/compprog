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

  ll N, X; cin >> N >> X;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  vector<ll> B(N-1);
  for (ll i = 0; i < N-1; i++) B[i] = A[i + 1] / A[i];
  vector<map<ll, ll>> rec(N);
  vector<ll> z(N);
  {
    ll t = X;
    for (ll i = N - 1; i >= 0; i--) {
      z[i] = t / A[i];
      t -= z[i] * A[i];
    }
  }
  auto func = [&](auto rF, ll i, auto& w, ll rem) -> ll {
    if (i == N - 1) return 1;
    auto it = rec[i].find(rem);
    if (it != rec[i].end()) return it->second;
    ll t = rF(rF, i + 1, w, rem - w[i] * A[i]);
    ll tt;
    if (w[i] > 0) {
      ll add = (B[i] - w[i]) * A[i];
      vector<ll> y(w);
      ll j = i + 1;
      while (true) {
	y[j]++;
	if (j == N-1) break;
	if (y[j] < B[j]) break;
	y[j] = 0;
	j++;
      }
      tt = rF(rF, i + 1, y, rem + add);
    }else {
      tt = 0;
    }
    rec[i][rem] = t + tt;
    return t + tt;
  };
  ll ans = func(func, 0, z, X);
  cout << ans << endl;

  return 0;
}

