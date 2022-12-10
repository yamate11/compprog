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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  auto A = vector(N + 1, ll());
  for (int i = 1; i < N + 1; i++) { ll v; cin >> v; A[i] = v; }
  vector<ll> ans(2 * N + 2);
  REP(i, 1, N + 1) {
    ans[2 * i] = ans[A[i]] + 1;
    ans[2 * i + 1] = ans[A[i]] + 1;
  }
  REPOUT(i, 1, 2 * N + 1 + 1, ans[i], "\n");

  return 0;
}

