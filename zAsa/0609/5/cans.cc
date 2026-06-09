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
  // @InpMVec(N, (P, A, B)) [2gk4mZsL]
  auto P = vector(N, ll());
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; P[i] = v1;
    ll v2; cin >> v2; A[i] = v2;
    ll v3; cin >> v3; B[i] = v3;
  }
  // @End [2gk4mZsL]

  vector tbl(N + 1, vector(1001, 0LL));
  REP(i, 0, 1001) tbl[N][i] = i;
  REPrev(i, N - 1, 0) {
    REP(j, 0, 1001) {
      if (j <= P[i]) {
        ll x = j + A[i];
        assert(x <= 1000);
        tbl[i][j] = tbl[i + 1][x];
      }else {
        ll x = j - B[i];
        if (x < 0) tbl[i][j] = tbl[i + 1][0];
        else tbl[i][j] = tbl[i + 1][x];
      }
    }
  }
  vector<ll> BS(N + 1);
  REP(i, 0, N) BS[i + 1] = BS[i] + B[i];
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll x; cin >> x;
    ll ans;
    if (x <= 1000) ans = tbl[0][x];
    else {
      ll i = ranges::lower_bound(BS, x - 1000) - BS.begin();
      if (i == ssize(BS)) {
        ans = x - BS[N];
      }else {
        ans = tbl[i][x - BS[i]];
      }
    }
    cout << ans << endl;
  }
  

  return 0;
}

