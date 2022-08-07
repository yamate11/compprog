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
    ll N; cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    ll up = -1;
    ll down = -1;
    REP(i, N - 1) {
      if (A[i] < A[i + 1]) up = i;
      if (down < 0 and A[i] > A[i + 1]) down = i;
    }
    if (up < 0 or down < 0) return true;
    return up < down;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << (solve() ? "YES" : "NO") << "\n";

  return 0;
}

