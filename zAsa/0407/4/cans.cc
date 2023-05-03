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

  ll N, D, K; cin >> N >> D >> K;
  // @InpMVec(D, ((L, dec=1), (R, dec=1))) [hyt5Cyu1]
  auto L = vector(D, ll());
  auto R = vector(D, ll());
  for (int i = 0; i < D; i++) {
    ll v1; cin >> v1; v1 -= 1; L[i] = v1;
    ll v2; cin >> v2; v2 -= 1; R[i] = v2;
  }
  // @End [hyt5Cyu1]
  // @InpMVec(K, ((S, dec=1), (T, dec=1))) [SfZtCo3F]
  auto S = vector(K, ll());
  auto T = vector(K, ll());
  for (int i = 0; i < K; i++) {
    ll v1; cin >> v1; v1 -= 1; S[i] = v1;
    ll v2; cin >> v2; v2 -= 1; T[i] = v2;
  }
  // @End [SfZtCo3F]

  vector<ll> cur(K);
  vector<ll> ans(K, -1LL);
  REP(i, 0, K) cur[i] = S[i];
  REP(i, 0, D) {
    REP(j, 0, K) {
      if (ans[j] >= 0) continue;
      if (L[i] <= cur[j] and cur[j] <= R[i]) {
        if (cur[j] < T[j]) {
          if (L[i] <= T[j] and T[j] <= R[i]) {
            ans[j] = i;
          }else {
            cur[j] = R[i];
          }
        }else if (T[j] < cur[j]) {
          if (L[i] <= T[j] and T[j] <= R[i]) {
            ans[j] = i;
          }else {
            cur[j] = L[i];
          }
        }else assert(0);
      }
    }
  }
  REPOUT(i, 0, K, ans[i] + 1, "\n");

  return 0;
}

