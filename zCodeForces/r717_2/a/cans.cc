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
    ll N, K; cin >> N >> K;
    vector<ll> A(N); REP(i, N) cin >> A[i];
    {
      ll i = 0;
      while (K > 0 and i < N - 1) {
        if (A[i] <= K) {
          A[N - 1] += A[i];
          K -= A[i];
          A[i] = 0;
        }else {
          A[i] -= K;
          A[N - 1] += K;
          break;
        }
        i++;
      }
    }
    REP(i, N) cout << A[i] << " ";
    cout << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

