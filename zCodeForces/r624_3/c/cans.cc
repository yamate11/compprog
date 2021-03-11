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
    ll N, M; cin >> N >> M;
    string s; cin >> s;
    vector<ll> P(M), app(N);
    for (ll i = 0; i < M; i++) {
      ll p; cin >> p;
      P[i] = p;
      app[p]++;
    }
    vector<ll> accum(N+1);
    for (ll i = N-1; i >= 0; i--) {
      accum[i] = accum[i+1] + app[i];
    }
    vector<ll> cnt(26);
    for (ll i = 1; i <= N; i++) {
      char c = s[i-1] - 'a';
      cnt[c] += accum[i];
    }
    for (ll i = 0; i < N; i++) cnt[s[i] - 'a']++;

    for (ll i = 0; i < 26; i++) {
      if (i > 0) cout << " ";
      cout << cnt[i];
    }
    cout << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

