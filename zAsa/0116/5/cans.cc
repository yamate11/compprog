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

// @@ !! LIM(binsearch f:updMaxMin)

// ---- inserted library file binsearch.cc

template<typename T>
T binsearch_i(auto check, T yes, T no, T err = (T)1) {
  while (abs(yes - no) > err) {
    T mid = (yes + no) / 2;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

template<typename T>
T binsearch_r(auto check, T yes, T no, T err, bool rel = true) {
  while (abs(yes - no) > err &&
         (!rel || abs(yes - no) > abs(yes) * err)) {
    T mid = (yes + no) / 2.0;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

ll border_with_hint(ll t, auto pred, auto hint) {
  double y = hint(t);
  double d = floor(y);
  double e = ceil(y);
  bool rd = pred(d, t);
  bool re = pred(e, t);
  if (rd && !re) return d;
  if (!rd && re) return e;
  for (ll i = 1; true; i++) {
    bool rd_i = pred(d - i, t);
    if (rd_i && !rd) return d - i;
    if (!rd_i && rd) return d - (i - 1);
    bool re_i = pred(e + i, t);
    if (re_i && !re) return e + i;
    if (!re_i && re) return e + (i - 1);
  }
}

// ---- end binsearch.cc

// ---- inserted function f:updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end f:updMaxMin

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W, T; cin >> H >> W >> T;
  vector<string> S(H);
  REP(i, 0, H) cin >> S[i];
  ll sx, sy, gx, gy;
  REP(i, 0, H) REP(j, 0, W) {
    if (S[i][j] == 'S') { sx = i; sy = j; }
    if (S[i][j] == 'G') { gx = i; gy = j; }
  }

  ll big = 1e10;
  auto check = [&](ll t) -> bool {
    vector dist(H, vector(W, vector(H, vector(W, big))));
    REP(x, 0, H) REP(y, 0, W) {
      dist[x][y][x][y] = 0;
      if (x + 1 < H) {
        dist[x][y][x + 1][y] = S[x + 1][y] == '#' ? t : 1;
        dist[x + 1][y][x][y] = S[x][y]     == '#' ? t : 1;
      }
      if (y + 1 < W) {
        dist[x][y][x][y + 1] = S[x][y + 1] == '#' ? t : 1;
        dist[x][y + 1][x][y] = S[x][y]     == '#' ? t : 1;
      }
    }
    REP(kx, 0, H) REP(ky, 0, W) REP(ix, 0, H) REP(iy, 0, W) REP(jx, 0, H) REP(jy, 0, W) {
      updMin(dist[ix][iy][jx][jy], dist[ix][iy][kx][ky] + dist[kx][ky][jx][jy]);
    }
    return dist[sx][sy][gx][gy] <= T;
  };
  ll ans = binsearch_i<ll>(check, 1, T + 10);
  cout << ans << endl;
  return 0;
}

