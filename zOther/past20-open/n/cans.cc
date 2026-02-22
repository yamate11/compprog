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

// @@ !! LIM(f:updMaxMin)

// ---- inserted function f:updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end f:updMaxMin

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, A, B; cin >> N >> A >> B;
  // @InpMVec(N, (C, D)) [4fRxwR9f]
  auto C = vector(N, ll());
  auto D = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; C[i] = v1;
    ll v2; cin >> v2; D[i] = v2;
  }
  // @End [4fRxwR9f]
  C.push_back(1);
  D.push_back(1);
  C.push_back(A);
  D.push_back(B);
  ll start = N;
  ll power = N + 1;
  ll big = 1e18;
  vector tbl(1LL << (N + 2), vector(N + 2, big));
  tbl[(1LL << start)][start] = 0;
  ll mask = (1LL << N) - 1;
  ll ans = big;
  REP(x, 0, 1LL << (N + 2)) {
    REP(p, 0, N + 2) {
      if (tbl[x][p] < big) {
        REP(q, 0, N + 2) {
          if (not (x >> q & 1)) {
            ll y = x | (1LL << q);
            ll a;
            if (x >> power & 1) a = max(abs(C[p] - C[q]),  abs(D[p] - D[q]));
            else                a =     abs(C[p] - C[q]) + abs(D[p] - D[q]);
            updMin(tbl[y][q], tbl[x][p] + a);
            if ((y & mask) == mask) updMin(ans, tbl[y][q]);
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}

