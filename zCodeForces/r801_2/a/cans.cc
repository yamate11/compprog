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
    ll vmax = -1e10;
    ll p = -1, q = -1;
    REP(i, N) REP(j, M) {
      ll a; cin >> a;
      if (a > vmax) {
        vmax = a;
        p = i;
        q = j;
      }
    }
    ll p0 = max(p + 1, N - p);
    ll q0 = max(q + 1, M - q);
    cout << p0 * q0 << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

