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

  ll N; cin >> N;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  vector tbl(N + 1, -1LL);
  auto f = [&](auto rF, ll n) -> ll {
    ll& ret = tbl[n];
    if (ret < 0) {
      if (n == 0) return ret = 0;
      else ret = 2 * rF(rF, n - 1) + A[n - 1];
    }
    return ret;
  };
  cout << f(f, N) << endl;

  return 0;
}

