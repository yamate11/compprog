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

  ll N; cin >> N;
  // @InpVec(N, X) [79NGZr4l]
  auto X = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; X[i] = v; }
  // @End [79NGZr4l]
  // @InpVec(N, Y) [r9XcJuOD]
  auto Y = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; Y[i] = v; }
  // @End [r9XcJuOD]

  deque<pll> deq;
  ll big = 1e18;
  ll ans = big;
  deq.emplace_back(Y[0], -big);
  REP(i, 1, N) {
    if (Y[i - 1] == Y[i]) continue;
    else if (Y[i - 1] < Y[i]) {
      deq.emplace_back(Y[i] - Y[i - 1], X[i - 1] + 1);
    }else { // Y{i - 1] > Y[i]
      ll d = Y[i - 1] - Y[i];
      while (d > 0) {
        auto [n, x] = deq.front(); deq.pop_front();
        if (x > -big) updMin(ans, X[i] - 1 - x);
        if (n > d) {
          deq.emplace_front(n - d, x);
          break;
        }else {
          d -= n;
        }
      }
    }
  }
  if (ans == big) ans = -1;
  cout << ans << endl;
  return 0;
}

