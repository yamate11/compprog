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

  ll N, K, S; cin >> N >> K >> S;
  ll big = 1e9;
  if (S < big) {
    REP(i, 0, K) cout << S << " ";
    REP(i, K, N) cout << big << " ";
    cout << endl;
  }else {
    REP(i, 0, K) cout << S << " ";
    REP(i, K, N) cout << 1 << " ";
    cout << endl;
  }

  return 0;
}

