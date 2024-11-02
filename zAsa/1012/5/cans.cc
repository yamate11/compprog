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

  ll N, M; cin >> N >> M;
  // @InpVec(N, A) [oRszBmqz]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [oRszBmqz]

  vector tbl(N + 1, set<ll>());
  REP(i, 0, N) {
    // 0 <= A[i] + (j + 1) * (i + 1) <= N
    // j >= divCeil(- A[i], i + 1) - 1
    // j <= divFloor(N - A[i], i + 1) - 1
    ll vmin = max(0LL, divCeil(-A[i], i + 1) - 1);
    ll vlim = min(M, divFloor(N - A[i], i + 1));
    REP(j, vmin, vlim) {
      ll x = A[i] + (j + 1) * (i + 1);
      tbl[x].insert(j);
    }
  }
  vector<ll> vec(M);
  vector<ll> ans(M);
  REP(i, 0, M) vec[i] = i;
  REP(x, 0, N + 1) {
    vector<ll> newVec;
    for (ll j : vec) {
      if (tbl[x].contains(j)) newVec.push_back(j);
      else ans[j] = x;
    }
    vec = move(newVec);
  }
  REPOUT(i, 0, M, ans[i], "\n");

  return 0;
}

