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

  ll N, W; cin >> N >> W;
  // @InpMVec(N, (vecW, vecV)) [7I1l69uh]
  auto vecW = vector(N, ll());
  auto vecV = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; vecW[i] = v1;
    ll v2; cin >> v2; vecV[i] = v2;
  }
  // @End [7I1l69uh]
  vector A(4, vector<ll>());
  ll w0 = vecW[0];
  REP(i, 0, N) A[vecW[i] - w0].push_back(vecV[i]);
  REP(i, 0, 4) ranges::sort(A[i], greater<ll>());
  vector B(4, vector<ll>());
  REP(i, 0, 4) {
    B[i].resize(ssize(A[i]) + 1);
    REP(j, 0, ssize(A[i])) B[i][j + 1] = B[i][j] + A[i][j];
  }
  ll s0 = ssize(A[0]);
  ll s1 = ssize(A[1]);
  ll s2 = ssize(A[2]);
  ll s3 = ssize(A[3]);
  ll ans = 0;
  REP(i, 0, s0 + 1) REP(j, 0, s1 + 1) REP(k, 0, s2 + 1) {
    ll w = w0 * i + (w0 + 1) * j + (w0 + 2) * k;
    if (w <= W) {
      ll m = min(s3, divFloor(W - w, w0 + 3));
      ll v = B[0][i] + B[1][j] + B[2][k] + B[3][m];
      ans = max(ans, v);
    }
  }
  cout << ans << "\n";
  return 0;
}

