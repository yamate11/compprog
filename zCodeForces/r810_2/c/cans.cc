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

  auto solve = [&]() -> bool {
    ll N, M, K; cin >> N >> M >> K;
    vector<ll> A(K); REP(i, K) cin >> A[i];
    auto chk = [&](ll p, ll q) -> bool {
      ll a = 0;
      bool hasThreeMore = false;
      REP(i, K) {
        ll t = A[i] / p;
        if (t < 2) continue;
        if (t >= 3) hasThreeMore = true;
        a += t;
      }
      if (a < q) return false;
      if (q % 2 == 0 or hasThreeMore) return true;
      return false;
    };
    return chk(N, M) or chk(M, N);
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << (solve() ? "Yes" : "No") << "\n";

  return 0;
}

