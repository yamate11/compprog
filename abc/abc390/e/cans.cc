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

  ll N, X; cin >> N >> X;
  // @InpMVec(N, ((V, dec=1), A, C)) [JfsUewnW]
  auto V = vector(N, ll());
  auto A = vector(N, ll());
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; v1 -= 1; V[i] = v1;
    ll v2; cin >> v2; A[i] = v2;
    ll v3; cin >> v3; C[i] = v3;
  }
  // @End [JfsUewnW]
                
  vector tbl(3, vector(X + 1, -1LL));
  REP(vit, 0, 3) tbl[vit][0] = 0;
  REP(i, 0, N) {
    REPrev(c, X - C[i], 0) if (tbl[V[i]][c] >= 0) updMax(tbl[V[i]][c + C[i]], tbl[V[i]][c] + A[i]);
  }
  vector<ll> atbl(X + 1, -1LL);
  atbl[0] = 1e18;
  REP(vit, 0, 3) {
    vector btbl(X + 1, 0LL);
    REP(c1, 0, X + 1) {
      if (atbl[c1] >= 0) {
        REP(c2, 0, X - c1 + 1) {
          if (tbl[vit][c2] >= 0) {
            updMax(btbl[c1 + c2], min(atbl[c1], tbl[vit][c2]));
          }
        }
      }
    }
    atbl = move(btbl);
  }
  ll ans = 0;
  REP(c, 0, X + 1) ans = max(ans, atbl[c]);
  cout << ans << endl;

  return 0;
}

