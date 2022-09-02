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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, Q, dec=1) [TrrZXS1u]
  auto Q = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; Q[i] = v; }
  // @End [TrrZXS1u]
  vector<ll> A(N), B(N), P(N);
  REP(i, 0, N) { P[Q[i]] = i; }
  A[0] = B[0] = 5e8;
  REP(i, 1, N) {
    A[i] = A[i - 1] + 1;
    B[i] = B[i - 1] - 1;
    ll d = P[i] - P[i - 1];
    if (d > 0) A[i] += d;
    else       B[i] += d;
  }
  REPOUT(i, 0, N, A[i], " ");
  REPOUT(i, 0, N, B[i], " ");

  return 0;
}

