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

  auto infig = [&]() -> ll {
    ll ret = 0;
    REP(i, 0, 4) {
      string s; cin >> s;
      REP(j, 0, 4) {
        ret = ret * 2 + (s[j] == '#' ? 1 : 0);
      }
    }
    return ret;
  };

  auto rot = [&](ll x) -> ll {
    ll ret = 0;
    REP(i, 0, 4) REP(j, 0, 4) if (x >> (i * 4 + j) & 1) ret |= 1LL << ((3 - j) * 4 + i);
    return ret;
  };

  using LL = optional<ll>;
  auto shiftUp = [&](ll x) -> LL {
    ll mask = ((1LL << 4) - 1) << 12;
    if (mask & x) return nullopt;
    return x << 4;
  };
  auto shiftDown = [&](ll x) -> LL {
    ll mask = 1LL << 4;
    if (mask & x) return nullopt;
    return x >> 4;
  };
  auto shiftRight = [&](ll x) -> LL {
    ll mask = 0x1111;
    if (mask & x) return nullopt;
    return x >> 1;
  };
  auto shiftLeft = [&](ll x) -> LL {
    ll mask = 0x8888;
    if (mask & x) return nullopt;
    return x << 1;
  };
  auto shiftR = [&](ll x, ll ii) -> LL {
    if (ii == 0) return x;
    if (ii > 0) {
      for (; ii > 0; ii--) {
        LL t = shiftDown(x);
        if (
      }
  }

  auto put = [&](ll& board, ll f, ll rr, ll ii, ll jj) -> bool {
    
  };

  auto fig = vector(3, vector(4, 0LL));
  REP(k, 0, 3) {
    fig[k][0] = infig();
    REP(r, 1, 4) fig[k][r] = rot(fig[k][r - 1]);
  }

  REP(i0, -3, 4) REP(j0, -3, 4) REP(r1, 0, 4) REP(i1, -3, 4) REP(j1, -3, 4) REP(r2, 0, 4) REP(i2, -3, 4) REP(j2, -3, 4) {
    ll board = 0;
    if (not put(board, fig[0], 0, i0, j0)) continue;
    if (not put(board, fig[0], r1, i1, j1)) continue;
    if (not put(board, fig[0], r2, i2, j2)) continue;
    if (board == (1LL << 16) - 1) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
  return 0;
}

