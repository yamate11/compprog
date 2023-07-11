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
  // @InpVec(H, A, type=string) [40dssJx3]
  auto A = vector(H, string());
  for (int i = 0; i < H; i++) { string v; cin >> v; A[i] = v; }
  // @End [40dssJx3]
  vector score(H, vector(W, optional<ll>()));
  
  ll big = 1e18;
  score[H - 1][W - 1] = 0;
  auto calc = [&](auto rF, ll r, ll c) -> ll {
    optional<ll>& ret = score[r][c];
    if (not ret) {
      ret = -big;
      if (r + 1 < H) {
        ll a = (A[r + 1][c] == '+') ? 1 : -1;
        ll s = a - rF(rF, r + 1, c);
        if (*ret < s) ret = s;
      }
      if (c + 1 < W) {
        ll a = (A[r][c + 1] == '+') ? 1 : -1;
        ll s = a - rF(rF, r, c + 1);
        if (*ret < s) ret = s;
      }
    }
    return *ret;
  };
  ll s = calc(calc, 0, 0);
  cout << (s > 0 ? "Takahashi" : s < 0 ? "Aoki" : "Draw") << endl;

  return 0;
}

