#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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

  ll N, K, Q; cin >> N >> K >> Q;
  vector<ll> A(K); REP(i, K) cin >> A[i];
  REP(_q, Q) {
    ll l; cin >> l; l--;
    if (A[l] == N or (l + 1 < K and A[l] + 1 == A[l + 1])) continue;
    A[l]++;
  }
  REP(i, K) cout << A[i] << " ";
  cout << endl;

  return 0;
}

