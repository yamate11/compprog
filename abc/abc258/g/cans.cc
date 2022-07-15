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

// @@ !! LIM(f:intDiv)

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

constexpr ll lim = 3000;
constexpr ll bssz = lim * lim;
using ull = unsigned long long;
constexpr ull full = ~((ull)0);

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  // auto enc = [&](ll i, ll j) -> ll { return i * lim + j; };

  ll N; cin >> N;
  ll nb = divCeil(N, 64);
  vector conn(N, vector<ull>(nb));
  REP(i, N) {
    string s; cin >> s;
    REP2(j, i + 1, N) if (s[j] == '1') conn[i][j / 64] |= (1ULL << (j % 64));
  }
  ll ans = 0;
  REP(k, N) {
    vector mmm(nb, (ull)0);
    REP(j, N) {
      if (conn[j][k / 64] >> (k % 64) & 1) mmm[j / 64] |= (1ULL << (j % 64));
    }
    ll lcnt = 0;
    REP(i, N) {
      if (conn[i][k / 64] >> (k % 64) & 1) {
        REP(jj, nb) {
          lcnt += __builtin_popcountll(conn[i][jj] & mmm[jj]);
        }
      }
    }
    ans += lcnt;
  }
  cout << ans << endl;

  return 0;
}

