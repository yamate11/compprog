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

  ll N, M; cin >> N >> M;
  // @InpVec(N, A) [RxjTEpB9]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [RxjTEpB9]
  // @InpVec(M, B) [E0zy5p6j]
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
  // @End [E0zy5p6j]

  sort(ALL(A));
  sort(ALL(B));
  ll i = 0;
  ll j = 0;
  ll ans = abs(A[0] - B[0]);
  while (i < N - 1 or j < M - 1) {
    ll x = abs(A[i] - B[j]);
    if (x < ans) ans = x;
    if (i == N - 1) j++;
    else if (j == M - 1) i++;
    else if (A[i] < B[j]) i++;
    else j++;
  }
  cout << ans << endl;
  return 0;
}

