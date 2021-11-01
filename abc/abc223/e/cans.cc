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

  ll X, Y, A, B, C; cin >> X >> Y >> A >> B >> C;
  auto check1 = [&]() -> bool {
    ll y1 = divCeil(A, X);
    ll y2 = divCeil(B, X);
    ll y3 = divCeil(C, X);
    return y1 + y2 + y3 <= Y;
  };
  auto check2 = [&]() -> bool {
    ll x1 = divCeil(A, Y);
    ll x2 = divCeil(B, Y);
    ll x3 = divCeil(C, Y);
    return x1 + x2 + x3 <= X;
  };
  auto check3x = [&](ll p, ll q, ll r) -> bool {
    ll x1 = divCeil(p, Y);
    if (x1 >= X) return false;
    ll y1 = divCeil(q, X - x1);
    ll y2 = divCeil(r, X - x1);
    return y1 + y2 <= Y;
  };
  auto check3 = [&]() -> bool {
    return check3x(A, B, C) or check3x(B, C, A) or check3x(C, A, B);
  };
  auto check4x = [&](ll p, ll q, ll r) -> bool {
    ll y1 = divCeil(p, X);
    if (y1 >= Y) return false;
    ll x1 = divCeil(q, Y - y1);
    ll x2 = divCeil(r, Y - y1);
    return x1 + x2 <= X;
  };
  auto check4 = [&]() -> bool {
    return check4x(A, B, C) or check4x(B, C, A) or check4x(C, A, B);
  };


  auto check = [&]() -> bool {
    if (check1()) return true;
    if (check2()) return true;
    if (check3()) return true;
    if (check4()) return true;
    return false;
  };
  cout << (check() ? "Yes" : "No") << endl;

  return 0;
}

