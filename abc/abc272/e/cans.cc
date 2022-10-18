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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

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
  // @InpVec(N, A) [kbhXyDOh]
  auto A = vector(N + 1, ll());
  for (int i = 1; i <= N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [kbhXyDOh]
  
  vector rec(M + 1, vector<ll>());
  REP(i, 1, N + 1) {
    ll lo;
    if (A[i] >= 0) lo = 0;
    else lo = divCeil(-A[i], i);
    ll hi = divFloor(N - A[i], i);
    if (lo <= 1) lo = 1;
    if (M <= hi) hi = M;
    for (ll j = lo; j <= hi; j++) {
      rec[j].push_back(A[i] + j * i);
    }
  }
  REP(j, 1, M + 1) {
    sort(ALL(rec[j]));
    auto last = std::unique(rec[j].begin(), rec[j].end());
    rec[j].erase(last, rec[j].end());
    bool found = false;
    REP(k, 0, SIZE(rec[j])) {
      if (rec[j][k] != k) {
        found = true;
        cout << k << "\n";
        break;
      }
    }
    if (not found) {
      cout << SIZE(rec[j]) << "\n";
    }
  }

  return 0;
}

