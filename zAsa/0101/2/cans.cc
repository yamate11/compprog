#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, W; cin >> N >> W;
  vector<ll> A(N + 2);
  REP(i, 0, N) cin >> A[i];
  vector rec(W + 1, false);
  ll ans = 0;
  REP(i, 0, N + 2) REP(j, i + 1, N + 2) REP(k, j + 1, N + 2) {
    ll x = A[i] + A[j] + A[k];
    if (0 < x and x <= W and not rec[x]) {
      rec[x] = true;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

