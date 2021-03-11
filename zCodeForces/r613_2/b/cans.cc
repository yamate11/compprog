#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> bool {
    ll N; cin >> N;
    vector<ll> A(N), S1(N+1), S2(N+1);
    for (ll i = 0; i < N; i++) {
      cin >> A[i];
      S1[i+1] = S1[i] + A[i];
    }
    for (ll i = 1; i <= N; i++) S2[i] = S1[i] - A[0];
    ll v1max = 0, v2max = 0, v1min = 0, v2min = 0;
    for (ll i = 0; i <= N; i++) {
      if (i < N) {
	v1max = max(v1max, S1[i]);
	v1min = min(v1min, S1[i]);
      }
      v2max = max(v2max, S2[i]);
      v2min = min(v2min, S2[i]);
    }
    ll diff1 = v1max - v1min;
    ll diff2 = v2max - v2min;
    ll diff0 = S1[N];
    return diff0 > max(diff1, diff2);

  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << (solve() ? "YES\n" : "NO\n");

  return 0;
}

