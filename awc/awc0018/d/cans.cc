#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
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

  ll N, K; cin >> N >> K;
  vector tbl(K + 1, false);
  tbl[0] = true;
  REP(i, 0, N) {
    ll c; cin >> c;
    REPrev(k, K, 0) {
      if (tbl[k] and k + c <= K) tbl[k + c] = true;
    }
  }
  REPrev(k, K, 0) {
    if (tbl[k]) {
      cout << k << endl;
      return 0;
    }
  }
  return 0;
}

