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
  // @InpVec(N, A) [bYTBpW3o]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [bYTBpW3o]
  ll GOLD = 0, SILVER = 1;
  vector<ll> B(N + 1);
  B[0] = GOLD;
  REP(i, 0, N) {
    if (i == N - 1) B[i + 1] = GOLD;
    else if (A[i] < A[i + 1]) B[i + 1] = GOLD;
    else B[i + 1] = SILVER;
  }
  vector<ll> ans(N);
  REP(i, 0, N) ans[i] = B[i] == B[i + 1] ? 0 : 1;
  REPOUT(i, 0, N, ans[i], " ");

  return 0;
}

