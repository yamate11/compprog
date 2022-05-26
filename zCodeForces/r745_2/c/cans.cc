#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll N, M; cin >> N >> M;
    vector<string> S(N);
    REP(i, N) cin >> S[i];
    auto val = [&](ll v, ll i, ll j) -> ll { return ll(v == (S[i][j] - '0')); };
    ll ans = 1e9;
    REP(i, N - 4) {
      vector<ll> num1(M);
      REP(j, M) num1[j] = val(1, i+1, j) + val(1, i+2, j) + val(1, i+3, j);
      vector<ll> costF(M + 1);
      REP2(p, 3, N - i - 1) {
        auto mcost = [&](ll j) -> ll { return num1[j] + val(0, i, j) + val(0, i + 1 + p, j); };
        costF[M] = 1e9;
        REP2R(j, M - 1, 0) costF[j] = min(p - num1[j], mcost(j) + costF[j + 1]);
        REP(j, M - 3) ans = min(ans, p - num1[j] + mcost(j + 1) + mcost(j + 2) + costF[j + 3]);
        REP(j, M) num1[j] += val(1, i + 1 + p, j);
      }
    }
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

