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

  ll N, M; cin >> N >> M;
  // @InpMVec(M, ((A, dec=1), (B, dec=1), (C, type=char))) [TflAbj0v]
  auto A = vector(M, ll());
  auto B = vector(M, ll());
  auto C = vector(M, char());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; A[i] = v1;
    ll v2; cin >> v2; v2 -= 1; B[i] = v2;
    char v3; cin >> v3; C[i] = v3;
  }
  // @End [TflAbj0v]

  vector dconn(N, vector(N, false));
  vector nbr(26, vector(N, vector<ll>()));
  REP(i, 0, M) {
    dconn[A[i]][B[i]] = true;
    dconn[B[i]][A[i]] = true;
    nbr[C[i] - 'a'][A[i]].push_back(B[i]);
    nbr[C[i] - 'a'][B[i]].push_back(A[i]);
  }
  if (dconn[0][N - 1]) {
    cout << 1 << endl;
    return 0;
  }
  vector seen(N, vector(N, false));
  using sta = tuple<ll, ll, ll>;
  queue<sta> que;
  seen[0][N - 1] = true;
  que.emplace(0, N - 1, 0);
  ll big = 1e18;
  ll ans = big;
  while (not que.empty()) {
    auto [x, y, len] = que.front(); que.pop();
    if (x == y) {
      updMin(ans, len);
      break;
    }
    if (dconn[x][y]) {
      updMin(ans, len + 1);
      continue;
    }
    if (ans == big) {
      REP(c, 0, 26) for (ll p : nbr[c][x]) for (ll q : nbr[c][y]) {
          if (not seen[p][q]) {
            seen[p][q] = true;
            que.emplace(p, q, len + 2);
          }
        }
    }
  }
  if (ans == big) ans = -1;
  cout << ans << endl;

  return 0;
}

