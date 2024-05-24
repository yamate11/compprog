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
  vector tbl(A + 1, vector(B + 1, -1LL));
  tbl[0][0] = 0;
  REP(i, 0, N) {
    ll w, v; cin >> w >> v;
    REPrev(a, A, 0) {
      REPrev(b, B, 0) {
        if (tbl[a][b] >= 0) {
          if (a + w <= A) updMax(tbl[a + w][b], tbl[a][b] + v);
          if (b + w <= B) updMax(tbl[a][b + w], tbl[a][b] + v);
        }
      }
    }
  }
  ll ans = 0;
  REP(a, 0, A + 1) REP(b, 0, B + 1) updMax(ans, tbl[a][b]);
  cout << ans << endl;

  return 0;
}

