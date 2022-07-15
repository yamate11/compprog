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

  string S; cin >> S;
  ll N = SIZE(S);
  const ll big = 1e18;
  vector tbl(N + 1, vector<ll>(2, 0));
  REP(i, N) {
    if (i == 0) {
      tbl[1][0] = 1;
    }else {
      if (S[i - 1] != S[i]) updMax(tbl[i + 1][0], tbl[i][0]);
      if (i > 
    }

    if (i == 0 or S[i - 1] != S[i]) tbl[i + 1][0] = tbl
  }



  }
  

  return 0;
}

