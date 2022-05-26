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
    ll N; cin >> N;
    vector<ll> A(N); REP(i, N) cin >> A[i];
    sort(ALL(A));
    REP2(i, 1, 1 + SIZE(A) / 2) {
      cout << A[i] << " " << A[0] << "\n";
    }

  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

