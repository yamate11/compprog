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
  // @InpVec(N, W) [k27Y61DG]
  auto W = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; W[i] = v; }
  // @End [k27Y61DG]
  // @InpVec(M, C) [jstwpGc8]
  auto C = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; C[i] = v; }
  // @End [jstwpGc8]
  ll c0 = *ranges::min_element(C);
  vector<ll> A(N + 1);
  REP(i, 0, N) A[i + 1] = A[i] + W[i];
  ll j = 0;
  ll ans = 0;
  REP(i, 0, N) {
    for (; j < N + 1 and A[j] - A[i] <= c0; j++);
    ans += j - 1 - i;
  }
  cout << ans << endl;

  return 0;
}

