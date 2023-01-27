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

  ll H, W; cin >> H >> W;
  vector<string> S(H);
  REP(i, 0, H) cin >> S[i];
  ll Q; cin >> Q;
  // @InpMVec(Q, (A, B)) [22lF9Vb8]
  auto A = vector(Q, ll());
  auto B = vector(Q, ll());
  for (int i = 0; i < Q; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
  }
  // @End [22lF9Vb8]
  ll x = 0, y = 0;
  REP(q, 0, Q) {
    ll a = A[q];
    ll b = B[q];
    if (x < a) x = a - 1 - x;
    else {
      x = x - a;
      x = H - a - 1 - x;
      x = x + a;
    }
    if (y < b) y = b - 1 - y;
    else {
      y = y - b;
      y = W - b - 1 - y;
      y = y + b;
    }
  }
  vector T(H, string(W, ' '));
  if (Q % 2 == 0) {
    REP(i, 0, H) REP(j, 0, W) {
      T[(x + i) % H][(y + j) % W] = S[i][j];
    }
  }else {
    REP(i, 0, H) REP(j, 0, W) {
      T[imod(x - i, H)][imod(y - j, W)] = S[i][j];
    }
  }
  REPOUT(i, 0, H, T[i], "\n");

  return 0;
}

