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

  ll N, X, Y; cin >> N >> X >> Y;
  vector<ll> A(N), B(N);
  REP(i, N) cin >> A[i];
  REP(i, N) cin >> B[i];
  vector<ll> cost(1 << N);
  REP2(x, 1, 1<<N) {
    ll t = __builtin_popcountll(x);
    ll j = 0;
    ll minC = LLONG_MAX;
    REP(i, t) {
      while (not ((x >> j) & 1)) j++;
      ll y = x ^ (1LL << j);
      ll c = cost[y] + (t - 1 - i) * Y + abs(B[j] - A[t - 1]) * X;
      minC = min(minC, c);
      j++;
    }
    cost[x] = minC;
  }
  cout << cost[(1 << N) - 1] << endl;

  return 0;
}

