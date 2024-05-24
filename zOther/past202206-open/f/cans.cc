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

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W; cin >> H >> W;
  // @InpGrid(H, W, S) [B5Qs12SK]
  auto S = vector(H, vector(W, ll()));
  for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) { ll v; cin >> v; S[i][j] = v; }
  // @End [B5Qs12SK]
  ll N; cin >> N;
  // @InpMVec(N, ((R, dec=1), (C, dec=1))) [HrXqYcTf]
  auto R = vector(N, ll());
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; v1 -= 1; R[i] = v1;
    ll v2; cin >> v2; v2 -= 1; C[i] = v2;
  }
  // @End [HrXqYcTf]

  REP(i, 0, N) {
    REPrev(j, R[i], 1) S[j][C[i]] = S[j - 1][C[i]];
    S[0][C[i]] = 0;
  }
  REP(i, 0, H) {
    REPOUT(j, 0, W, S[i][j], " ");
  }

  return 0;
}

