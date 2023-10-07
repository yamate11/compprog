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

  string S, T; cin >> S >> T;
  ll ns = SIZE(S);
  ll nt = SIZE(T);
  auto tbl = vector(ns + 1, vector(nt + 1, 0LL));
  REP(i, 0, ns + 1) REP(j, 0, nt + 1) {
    if (i == 0 or j == 0) tbl[i][j] = 0;
    else {
      if (S[i - 1] != T[j - 1]) tbl[i][j] = tbl[i - 1][j - 1] + 1;
      else tbl[i][j] = max(tbl[i - 1][j], tbl[i][j - 1]);
    }
  }
  cout << tbl[ns][nt] << endl;
  return 0;
}

