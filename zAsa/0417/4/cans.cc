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
  // @InpMVec(N, (T, X, A)) [rWXlbBH8]
  auto T = vector(N, ll());
  auto X = vector(N, ll());
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; T[i] = v1;
    ll v2; cin >> v2; X[i] = v2;
    ll v3; cin >> v3; A[i] = v3;
  }
  // @End [rWXlbBH8]

  auto lim = 1e5;
  vector<ll> markX(lim + 1, -1LL);
  vector<ll> markA(lim + 1, 0LL);
  REP(i, 0, N) markX[T[i]] = X[i];
  REP(i, 0, N) markA[T[i]] = A[i];

  vector<ll> tbl_init(5, -1LL);
  auto tbl = tbl_init;
  tbl[0] = 0;
  REP(t, 1, lim + 1) {
    auto prev = move(tbl);
    tbl = tbl_init;
    REP(x, 0, 5) {
      ll a = 0;
      if (markX[t] == x) a = markA[t];
      ll b = prev[x];
      if (x < 4) b = max(b, prev[x + 1]);
      if (x > 0) b = max(b, prev[x - 1]);
      if (b < 0) tbl[x] = b;
      else tbl[x] = a + b;
    }
  }
  ll ans = *max_element(ALL(tbl));
  cout << ans << endl;
  return 0;
}

