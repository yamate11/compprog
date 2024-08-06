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

  ll N, M, L; cin >> N >> M >> L;
  // @InpVec(N, A) [hxtEVl6H]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [hxtEVl6H]
  // @InpVec(M, B) [NsFPk6M9]
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
  // @End [NsFPk6M9]
  vector excl(N, vector<ll>());
  REP(i, 0, L) {
    ll c, d; cin >> c >> d; c--; d--;
    excl[c].push_back(d);
  }
  vector<ll> ordA(N, 0LL);
  iota(ALL(ordA), 0);
  sort(ALL(ordA), [&](ll i, ll j) -> bool { return A[i] > A[j]; });
  vector<ll> ordB(M, 0LL);
  iota(ALL(ordB), 0);
  sort(ALL(ordB), [&](ll i, ll j) -> bool { return B[i] > B[j]; });

  vector te(M, false);
  ll ans = -1;
  REP(ii, 0, N) {
    ll i = ordA[ii];
    for (ll j : excl[i]) te[j] = true;

    REP(jj, 0, M) {
      ll j = ordB[jj];
      if (not te[j]) {
        ans = max(ans, A[i] + B[j]);
        break;
      }
    }
    for (ll j : excl[i]) te[j] = false;
  }
  cout << ans << endl;

  return 0;
}

