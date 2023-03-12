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

  ll H, W; cin >> H >> W;
  vector<string> A(H);
  REP(i, 0, H) cin >> A[i];
  vector red(H, string(W, '.'));
  vector blue(H, string(W, '.'));
  REP(i, 0, H) {
    if (i % 2 == 0) REP(j, 1, W - 1) red[i][j] = '#';
    else REP(j, 1, W - 1) blue[i][j] = '#';
    red[i][0] = '#';
    blue[i][W - 1] = '#';
  };
  REP(i, 0, H) REP(j, 0, W) {
    if (A[i][j] == '#') red[i][j] = blue[i][j] = '#';
  }
  REP(i, 0, H) cout << red[i] << "\n";
  cout << "\n";
  REP(i, 0, H) cout << blue[i] << "\n";
  
  

  return 0;
}

