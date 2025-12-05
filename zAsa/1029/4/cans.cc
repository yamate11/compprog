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
  // @InpVec(N, A) [2C38az29]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [2C38az29]
  // @InpVec(N, B) [Ltj7wIph]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [Ltj7wIph]
  // @InpVec(N, C) [vqtwL8wa]
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
  // @End [vqtwL8wa]

  ranges::sort(A);
  ranges::sort(B);
  ranges::sort(C);

  vector<ll> P(N);
  REP(i, 0, N) P[i] = ranges::lower_bound(A, B[i]) - A.begin();
  REP(i, 1, N) P[i] += P[i - 1];
  ll ans = 0;
  REP(i, 0, N) {
    ll j = ranges::lower_bound(B, C[i]) - B.begin();
    if (j > 0) ans += P[j - 1];
  }
  cout << ans << endl;
  return 0;
}

