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

  ll N, M, Q; cin >> N >> M >> Q;
  // @InpMVec(M, ((A, dec=1), (B, dec=1), C)) [kS6gJahY]
  auto A = vector(M, ll());
  auto B = vector(M, ll());
  auto C = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; A[i] = v1;
    ll v2; cin >> v2; v2 -= 1; B[i] = v2;
    ll v3; cin >> v3; C[i] = v3;
  }
  // @End [kS6gJahY]
  using sta = tuple<ll, ll, ll>;
  vector query(Q, sta());
  vector stopped(M, false);
  REP(q, 0, Q) {
    ll t; cin >> t;
    if (t == 1) {
      ll i; cin >> i; i--;
      query[q] = sta(1, i, -1);
      stopped[i] = true;
    }else if (t == 2) {
      ll x, y; cin >> x >> y; x--; y--;
      query[q] = sta(2, x, y);
    }
  }

  ll big = 1e18;
  vector dist(N, vector(N, big));
  REP(i, 0, N) dist[i][i] = 0;
  REP(m, 0, M) if (not stopped[m]) {
    updMin(dist[A[m]][B[m]], C[m]);
    updMin(dist[B[m]][A[m]], C[m]);
  }
  REP(k, 0, N) REP(i, 0, N) REP(j, 0, N) updMin(dist[i][j], dist[i][k] + dist[k][j]);
  vector<ll> ans(Q, -2LL);
  REPrev(q, Q - 1, 0) {
    auto [t, x, y] = query[q];
    if (t == 1) {
      ll m = x;
      REP(i, 0, N) REP(j, 0, N) {
        updMin(dist[i][j], dist[i][A[m]] + C[m] + dist[B[m]][j]);
        updMin(dist[i][j], dist[i][B[m]] + C[m] + dist[A[m]][j]);
      }
    }else if (t == 2) {
      ans[q] = dist[x][y] == big ? -1 : dist[x][y];
    }
  }
  REP(q, 0, Q) {
    if (ans[q] == -2) continue;
    cout << ans[q] << "\n";
  }

  return 0;
}

