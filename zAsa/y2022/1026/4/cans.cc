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

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W; cin >> H >> W;
  // @InpGrid(H, W, S, type=char) [AKR1U03p]
  auto S = vector(H, vector(W, char()));
  for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) { char v; cin >> v; S[i][j] = v; }
  // @End [AKR1U03p]
  ll ans = 0;
  REP(i, 0, H - 1) REP(j, 0, W - 1) {
    ll b = 0, w = 0;
    REP(di, 0, 2) REP(dj, 0, 2) {
      if (S[i + di][j + dj] == '.') w++; else b++;
    }
    if (w == 3 or b == 3) ans++;
  }
  cout << ans << endl;

  return 0;
}

