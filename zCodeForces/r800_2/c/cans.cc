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
    ll n = N;
    while (n - 1 >= 0 and A[n - 1] == 0) n--;
    if (n == 0) return true;
    REP2(i, 1, n) A[i]++;
    REP2R(i, n - 1, 1) {
      if (A[i] > 0) return false;
      A[i - 1] += A[i] - 1;
    }
    return A[0] == 0;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << (solve() ? "Yes\n" : "No\n");

  return 0;
}

