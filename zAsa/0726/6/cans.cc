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

// @@ !! LIM(unordered_map f:intDiv)

// ---- inserted library file unordered_map.cc

/* This code is based on https://codeforces.com/blog/entry/62393 */

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
*/

struct safe_custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// ---- end unordered_map.cc

// ---- inserted function f:intDiv from util.cc
// imod, divFloor, divCeil

// imod(x, y) : remainder of x for y
// for y > 0:
//   imod(x, y)  = r where x = dy + r, 0 <= r < y
//   imod(x, -y) = r where x = dy + r, 0 >= r > y
// Thus, imod( 10,  7) =  3
//       imod(-10,  7) =  4
//       imod( 10, -7) = -4
//       imod(-10, -7) = -3
ll imod(ll x, ll y) {
  ll v = x % y;
  if ((x >= 0) == (y >= 0)) return v;
  else                      return v == 0 ? 0 : v + y;
}

// Integer Division; regardless pos/neg
ll divFloor(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return x / y;
    else       return (x - y - 1) / y;
  }else {
    if (y > 0) return (x - y + 1) / y;
    else       return x / y;
  }
}

ll divCeil(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return (x + y - 1) / y;
    else       return x / y;
  }else {
    if (y > 0) return x / y;
    else       return (x + y + 1) / y;
  }
}
//   Just a note.  For d \in Z and t \in R,
//       d < t <=> d < ceil(t),     d <= t <=> d <= floor(t),
//       d > t <=> d > floor(t),    d >= t <=> d >= ceil(t).

// ---- end f:intDiv

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpGrid(N, N, P) [EwzwLena]
  auto P = vector(N, vector(N, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) { ll v; cin >> v; P[i][j] = v; }
  // @End [EwzwLena]
  // @InpGrid(N, N - 1, R) [qkWTOHwN]
  auto R = vector(N, vector(N - 1, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < N - 1; j++) { ll v; cin >> v; R[i][j] = v; }
  // @End [qkWTOHwN]
  // @InpGrid(N - 1, N, D) [kVlVUw9L]
  auto D = vector(N - 1, vector(N, ll()));
  for (int i = 0; i < N - 1; i++) for (int j = 0; j < N; j++) { ll v; cin >> v; D[i][j] = v; }
  // @End [kVlVUw9L]

  auto better = [&](const pll& p1, const pll& p2) -> bool {
    return p1.first < p2.first or (p1.first == p2.first and p1.second > p2.second);
  };

  using mymap = unordered_map<ll, pll, safe_custom_hash>;
  vector tbl(N, vector(N, mymap()));
  tbl[0][0][0] = pll(0, 0);
  REP(i, 0, N) REP(j, 0, N) {
    for (auto [p, _z] : tbl[i][j]) {
      auto [n, rem] = _z;

      auto f = [&](auto& mp, ll p0, const pll& new_pair) -> void {
        auto [it, b] = mp.try_emplace(p0, new_pair);
        if (not b and better(new_pair, it->second)) it->second = new_pair;
      };
      
      ll p0 = max(p, P[i][j]);
      if (i < N - 1) {
        ll d = divCeil(D[i][j] - rem, p0);
        f(tbl[i + 1][j], p0, pll(n + d + 1, d * p0 + rem - D[i][j]));
      }
      if (j < N - 1) {
        ll r = divCeil(R[i][j] - rem, p0);
        f(tbl[i][j + 1], p0, pll(n + r + 1, r * p0 + rem - R[i][j]));
      }
    }
  }
  ll ans = 1e18;
  for (auto [p, z] : tbl[N - 1][N - 1]) {
    auto [n, rem] = z;
    ans = min(ans, n);
  }
  cout << ans << endl;

  return 0;
}

