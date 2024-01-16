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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, Q; cin >> N >> M >> Q;
  // @InpMVec(N, (W, V)) [3MUEbbIu]
  auto W = vector(N, ll());
  auto V = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; W[i] = v1;
    ll v2; cin >> v2; V[i] = v2;
  }
  // @End [3MUEbbIu]
  // @InpVec(M, X) [XnOA29kF]
  auto X = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; X[i] = v; }
  // @End [XnOA29kF]

  vector<ll> ord(N); REP(i, 0, N) ord[i] = i;
  sort(ALL(ord), [&](ll i, ll j) -> bool { return V[i] > V[j]; });
  vector<ll> ordX(M); REP(i, 0, M) ordX[i] = i;
  sort(ALL(ordX), [&](ll i, ll j) -> bool { return X[i] < X[j]; });

  REP(_q, 0, Q) {
    ll l, r; cin >> l >> r; l--; r--;
    ll ans = 0;
    vector<bool> used(M, false);
    REP(i, l, r + 1) used[i] = true;
    REP(i, 0, N) {
      ll j = ord[i];
      REP(p, 0, M) {
        ll q = ordX[p];
        if (not used[q] and X[q] >= W[j]) {
          used[q] = true;
          ans += V[j];
          break;
        }
      }
    }
    cout << ans << "\n";
  }

  

  return 0;
}

