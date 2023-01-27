#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
#include <atcoder/maxflow>
using namespace atcoder;
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
  vector<string> S(H);
  REP(i, 0, H) cin >> S[i];
  ll c = 0;
  enum {ONE, HORIZ, VERT};
  auto enc = [&](ll tp, ll r, ll c) -> ll {
    if (tp == ONE) return 2 + r * W + c;
    else if (tp == HORIZ) return 2 + H * W + r * (W - 1) + c;
    else if (tp == VERT) return 2 + H * W + H * (W - 1) + r * W + c;
    else assert(0);
  };
  mf_graph<ll> g(2 + H*W + H*(W-1) + (H-1)*W);
  REP(i, 0, H) REP(j, 0, W) {
    enc(ONE, i
  }

  return 0;
}

