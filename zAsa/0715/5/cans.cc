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
  // @InpMVec(M, (L, D, K, C, (A, dec=1), (B, dec=1))) [BlH4ZdMP]
  auto L = vector(M, ll());
  auto D = vector(M, ll());
  auto K = vector(M, ll());
  auto C = vector(M, ll());
  auto A = vector(M, ll());
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; L[i] = v1;
    ll v2; cin >> v2; D[i] = v2;
    ll v3; cin >> v3; K[i] = v3;
    ll v4; cin >> v4; C[i] = v4;
    ll v5; cin >> v5; v5 -= 1; A[i] = v5;
    ll v6; cin >> v6; v6 -= 1; B[i] = v6;
  }
  // @End [BlH4ZdMP]
  vector bwd(N, vector<ll>());
  REP(i, 0, M) bwd[B[i]].push_back(i);
  ll big = 1LL << 60;
  vector<ll> last(N, -big);
  priority_queue<pll> pque;
  last[N - 1] = big;
  pque.emplace(big, N - 1);
  while (not pque.empty()) {
    auto [t, nd] = pque.top(); pque.pop();
    if (last[nd] == t) {
      for (ll idx : bwd[nd]) {
        if (ll j = min(K[idx] - 1, (t - (L[idx] + C[idx])) / D[idx]); j >= 0) {
          ll new_last = L[idx] + j * D[idx];
          if (new_last > last[A[idx]]) {
            last[A[idx]] = new_last;
            pque.emplace(new_last, A[idx]);
          }
        }
      }
    }
  }
  REP(i, 0, N  - 1) {
    if (last[i] == -big) {
      cout << "Unreachable\n";
    }else {
      cout << last[i] << "\n";
    }
  }

  return 0;
}

