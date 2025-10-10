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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpMVec(N, (P, A, B)) [tYjLmTpX]
  auto P = vector(N, ll());
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; P[i] = v1;
    ll v2; cin >> v2; A[i] = v2;
    ll v3; cin >> v3; B[i] = v3;
  }
  // @End [tYjLmTpX]

  ll lim = 1000;
  vector tbl(N + 1, vector(lim + 1, 0LL));
  REP(i, 0, lim + 1) tbl[N][i] = i;
  REPrev(i, N - 1, 0) {
    REP(t, 0, lim + 1) {
      if (t <= P[i]) tbl[i][t] = tbl[i + 1][t + A[i]];
      else           tbl[i][t] = tbl[i + 1][max(t - B[i], 0LL)];
    }
  }

  vector<ll> SB(N + 1, 0LL);
  REP(i, 0, N) SB[i + 1] = SB[i] + B[i];

  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll x; cin >> x;
    if (x <= lim) {
      cout << tbl[0][x] << "\n";
    }else {
      ll j = lower_bound(ALL(SB), x - lim) - SB.begin();
      if (j > N) cout << x - SB[N] << "\n";
      else       cout << tbl[j][x - SB[j]] << "\n";
    }
  }


  return 0;
}

