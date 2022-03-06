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
    vector<ll> A(N); REP(i, N) cin >> A[i];
    {
      ll s = 0; REP(i, N) s ^= A[i];
      if (s == 0) return true;
    }
    for (ll k = 1; k < N; k++) {
      ll s = 0; REP(i, k) s ^= A[i];
      ll t = 0;
      ll cnt = 0;
      REP2(i, k, N) {
        t ^= A[i];
        if (t == s) {
          cnt++;
          t = 0;
        }
      }
      if (cnt > 0 and t == 0) return true;
    }
    return false;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << (solve() ? "YES\n" : "NO\n");

  return 0;
}

