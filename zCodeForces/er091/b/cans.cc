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
    string S; cin >> S;
    ll N = S.size();
    vector<ll> c(128);
    for (ll i = 0; i < N; i++) {
      c[S[i]]++;
    }
    ll nR = c['R'], nS = c['S'], nP = c['P'];
    char w = 0;
    if (nR <= nP && nS <= nP) w = 'S';
    if (nR <= nS && nP <= nS) w = 'R';
    if (nS <= nR && nP <= nR) w = 'P';
    for (ll i = 0; i < N; i++) cout << w;
    cout << "\n";


  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

