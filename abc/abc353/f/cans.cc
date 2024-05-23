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

// @@ !! LIM(f:updMaxMin)

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

  vector<ll> dx{-1, 1, 0, 0};
  vector<ll> dy{0, 0, -1, 1};

  ll big = 1e18;
  
  auto solve = [&]() -> ll {
    ll K; cin >> K;
    ll sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
  
    if (K == 1) {
      return abs(sx - tx) + abs(sy - ty);
    }
    sx += 2 * K;
    sy += 2 * K;
    tx += 2 * K;
    ty += 2 * K;

    auto coord = [&](ll x, ll y) -> tuple<ll, ll, ll, ll> {
      ll p = x / K;
      ll q = y / K;
      ll r = x % K;
      ll t = y % K;
      if ((p + q) % 2 == 0) return {p, q, r, t};
      else return {p, q, -1, -1};
    };

    auto bigdist = [&](ll p1, ll q1, ll p2, ll q2) -> ll {
      ll pp = abs(p2 - p1);
      ll qq = abs(q2 - q1);
      if (K == 2) {
        if (pp < qq) swap(pp, qq);
        return 2 * qq + 3 * (pp - qq) / 2;
      }else {
        ll x = (pp + qq) / 2;
        ll y = (pp - qq) / 2;
        return 2 * (abs(x) + abs(y));
      }
    };

    auto outdist = [&](ll ddx, ll ddy, ll r, ll t) -> ll {
      if (ddx > 0) return K - r;
      if (ddx < 0) return r + 1;
      if (ddy > 0) return K - t;
      if (ddy < 0) return t + 1;
      assert(0);
    };

    auto [sp, sq, sr, st] = coord(sx, sy);
    auto [tp, tq, tr, tt] = coord(tx, ty);
    if (sr < 0 and tr < 0) return bigdist(sp, sq, tp, tq);
    else if (sr >= 0 and tr >= 0) {
      ll ans = big;
      REP(i, 0, 4) REP(j, 0, 4) {
        updMin(ans, outdist(dx[i], dy[i], sr, st) + outdist(dx[j], dy[j], tr, tt)
               + bigdist(sp + dx[i], sq + dy[i], tp + dx[j], tq + dy[j]));
      }
      if (sp == tp and sq == tq) {
        updMin(ans, abs(sr - tr) + abs(st - tt));
      }
      return ans;
    }else {
      if (sr >= 0) {
        swap(sp, tp); swap(sq, tq); swap(sr, tr); swap(st, tt);
      }
      ll ans = big;
      REP(i, 0, 4) {
        updMin(ans, outdist(dx[i], dy[i], tr, tt) + bigdist(tp + dx[i], tq + dy[i], sp, sq));
      }
      return ans;
    }


  };

  cout << solve() << endl;
  

  return 0;
}

