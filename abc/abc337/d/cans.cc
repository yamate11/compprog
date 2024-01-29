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

  ll H, W, K; cin >> H >> W >> K;
  // @InpVec(H, S, type=string) [7inq4242]
  auto S = vector(H, string());
  for (int i = 0; i < H; i++) { string v; cin >> v; S[i] = v; }
  // @End [7inq4242]

  ll big = 1e18;

  auto func = [&](string T) -> ll {
    ll ret = big;
    ll N = SIZE(T);
    ll no = 0;
    ll nx = 0;
    REP(i, 0, K) {
      if      (T[i] == 'o') no++;
      else if (T[i] == 'x') nx++;
    }
    REP(i, K, N) {
      if (nx == 0) updMin(ret, K - no);
      if      (T[i] == 'o') no++;
      else if (T[i] == 'x') nx++;
      if      (T[i - K] == 'o') no--;
      else if (T[i - K] == 'x') nx--;
    }
    if (nx == 0) updMin(ret, K - no);
    return ret;
  };

  string S1, S2;
  REP(i, 0, H) {
    REP(j, 0, W) S1.push_back(S[i][j]);
    S1.push_back('x');
  }
  REP(j, 0, W) {
    REP(i, 0, H) S2.push_back(S[i][j]);
    S2.push_back('x');
  }
  ll a = func(S1);
  ll b = func(S2);
  ll ans = min(a, b);
  if (ans >= big) ans = -1;
  cout << ans << endl;
  

  return 0;
}

