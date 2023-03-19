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
  // @InpVec(N, A) [vuML0sEe]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [vuML0sEe]
  // @InpVec(M, B) [REiRjN8h]
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
  // @End [REiRjN8h]

  using sta = tuple<ll, ll, ll>;
  vector<sta> C;
  REP(i, 0, N) C.emplace_back(A[i], 0, i);
  REP(i, 0, M) C.emplace_back(B[i], 1, i);
  sort(ALL(C));
  vector<ll> ansA(N);
  vector<ll> ansB(M);
  for (ll i = 0; i < N + M; i++) {
    auto [x, c, idx] = C[i];
    if (c == 0) ansA[idx] = i + 1;
    else ansB[idx] = i + 1;
  }
  REPOUT(i, 0, N, ansA[i], " ");
  REPOUT(i, 0, M, ansB[i], " ");

  return 0;
}

