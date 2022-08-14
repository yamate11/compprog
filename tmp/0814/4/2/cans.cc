#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define InpVec(vec, n) vector<ll> vec(n); REP(i, 0, (n)) cin >> vec[i]
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll R, C, D; cin >> R >> C >> D;
  vector A(2001, vector(2001, 0LL));
  REP(r, 0, R) REP(c, 0, C) cin >> A[r][c];
  ll ans = 0;
  REP(t, 0, D + 1) if (t % 2 == D % 2) REP(r, 0, t + 1) ans = max(ans, A[r][t - r]);
  cout << ans << endl;


  return 0;
}

