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

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<string> S(N);
  REP(i, 0, N) cin >> S[i];

  auto f = [&](ll i, ll j) -> char { return S[imod(i, N)][imod(j, N)]; };

  vector widthO(N, vector(N, 0LL));
  vector widthE(N, vector(N, 0LL));
  REP(i, 0, N) REP(j, 0, N) {
    REP(k, 1, N + 2) {
      if (f(i + k, j - k) != f(i - k, j + k)) break;
      widthO[i][j] = k;
    }
    REP(k, 1, N + 2) {
      if (f(i + k - 1, j - k + 1) != f(i - k, j + k)) break;
      widthE[i][j] = k;
    }
  }
  auto wo = [&](ll i, ll j) -> ll { return widthO[imod(i, N)][imod(j, N)]; };
  auto we = [&](ll i, ll j) -> ll { return widthE[imod(i, N)][imod(j, N)]; };

  ll ans = 0;
  REP(i, 0, N) REP(j, 0, N) {
    auto check = [&]() -> bool {
      REP(x, 0, N) {
        {
          ll req = min(x, N - 1 - x);
          if (wo(i + x, j + x) < req) return false;
        }
        if (x < N - 1) {
          ll req = min(x + 1, N - 1 - x);
          if (we(i + x + 1, j + x) < req) return false;
        }
      }
      return true;
    };
    if (check()) ans++;
  }
  cout << ans << endl;

  return 0;
}

