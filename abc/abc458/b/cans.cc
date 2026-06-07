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

  ll H, W; cin >> H >> W;
  vector vec(H, vector(W, 4));
  if (H == 1 and W == 1) {
    vec[0][0] = 0;
  }else if (H == 1) {
    REP(j, 0, W) vec[0][j] = 2;
    vec[0][0] = vec[0][W - 1] = 1;
  }else if (W == 1) {
    REP(i, 0, H) vec[i][0] = 2;
    vec[0][0] = vec[H - 1][0] = 1;
  }else {
    REP(i, 0, H) {
      vec[i][0] = vec[i][W - 1] = 3;
    }
    REP(i, 0, W) {
      vec[0][i] = vec[H - 1][i] = 3;
    }
    vec[0][0] = vec[H - 1][0] = vec[0][W - 1] = vec[H - 1][W - 1] = 2;
  }
  REP(i, 0, H) {
    REPOUT(j, 0, W, vec[i][j], " ");
  }

  return 0;
}

