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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K, S; cin >> N >> K >> S;
  vector<ll> ans(N);
  ll lim = 1e9;
  if (S == lim) {
    REP(i, 0, K) ans[i] = S;
    REP(i, K, N) ans[i] = 1;
  }else {
    REP(i, 0, K) ans[i] = S;
    REP(i, K, N) ans[i] = S + 1;
  }
  REPOUT(i, 0, N, ans[i], " ");

  return 0;
}

