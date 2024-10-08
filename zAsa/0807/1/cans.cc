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

  ll N, M; cin >> N >> M;
  // @InpVec(N, A) [IgpAfyAi]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [IgpAfyAi]
  // @InpVec(M, B) [VwQMKXFE]
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
  // @End [VwQMKXFE]

  vector<tuple<ll, ll, ll>> vec;
  REP(i, 0, N) vec.emplace_back(A[i], 0, i);
  REP(i, 0, M) vec.emplace_back(B[i], 1, i);
  sort(ALL(vec));
  vector<ll> ansA(N);
  vector<ll> ansB(M);
  REP(i, 0, N + M) {
    auto [x, e, idx] = vec[i];
    if (e == 0) ansA[idx] = i;
    else ansB[idx] = i;
  }
  REPOUT(i, 0, N, ansA[i] + 1, " ");
  REPOUT(i, 0, M, ansB[i] + 1, " ");


  return 0;
}

