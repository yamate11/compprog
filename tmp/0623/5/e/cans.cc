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

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto req = [&](ll p, auto vec) -> ll {
    if (p <= 0) return 1.5e18;
    ll ret = 0;
    for (ll v : vec) ret += divCeil(v, p);
    return ret;
  };
  auto solve = [&]() -> bool {
    ll X, Y, A, B, C; cin >> X >> Y >> A >> B >> C;
    using vll = vector<ll>;
    if (req(X, vll({A, B, C})) <= Y) return true;
    if (req(Y, vll({A, B, C})) <= X) return true;
    if (req(X - divCeil(A, Y), vll({B, C})) <= Y) return true;
    if (req(X - divCeil(B, Y), vll({C, A})) <= Y) return true;
    if (req(X - divCeil(C, Y), vll({A, B})) <= Y) return true;
    if (req(Y - divCeil(A, X), vll({B, C})) <= X) return true;
    if (req(Y - divCeil(B, X), vll({C, A})) <= X) return true;
    if (req(Y - divCeil(C, X), vll({A, B})) <= X) return true;
    return false;
  };

  cout << (solve() ? "Yes" : "No") << endl;

  return 0;
}

