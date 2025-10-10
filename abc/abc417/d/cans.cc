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
  // @InpMVec(N, (P, A, B)) [9X9hRRmB]
  auto P = vector(N, ll());
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; P[i] = v1;
    ll v2; cin >> v2; A[i] = v2;
    ll v3; cin >> v3; B[i] = v3;
  }
  // @End [9X9hRRmB]
  
  ll lim = 1010;
  vector tbl(N + 1, vector(lim, 0LL));
  REP(i, 0, lim) tbl[N][i] = i;
  REPrev(i, N - 1, 0) {
    REP(x, 0, lim) {
      if (x <= P[i]) tbl[i][x] = tbl[i + 1][x + A[i]];
      else           tbl[i][x] = tbl[i + 1][max(x - B[i], 0LL)];
    }
  }

  vector<ll> SB(N + 1, 0LL);
  REP(i, 0, N) SB[i + 1] = SB[i] + B[i];

  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll ans;
    ll x; cin >> x;
    if (x < lim) ans = tbl[0][x];
    else {
      ll i = lower_bound(ALL(SB), x - (lim - 1)) - SB.begin();
      if (i == N + 1) {
        ans = x - SB[N];
      }else {
        ll t = x - SB[i];
        if (t < 0) t = 0;
        ans = tbl[i][t];
      }
    }
    cout << ans << "\n";
  }


  return 0;
}

