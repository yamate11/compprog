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

  ll N; cin >> N;
  // @InpVec(N, A) [mttXsm0L]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [mttXsm0L]
  // @InpVec(N, B) [II7FhN0a]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [II7FhN0a]
  // @InpVec(N, C) [shucpbif]
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
  // @End [shucpbif]

  sort(ALL(A));
  sort(ALL(B));
  sort(ALL(C));

  ll i = 0, j = 0, k =0 ;
  ll ans = 0;
  while (i < N) {
    while (j < N and A[i] >= B[j]) j++;
    if (j == N) break;
    while (k < N and B[j] >= C[k]) k++;
    if (k == N) break;
    ans++;
    i++; j++; k++;
  }
  cout << ans << endl;

  return 0;
}

