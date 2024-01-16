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
  // @InpVec(N, P, dec=1) [ZvVe6KNN]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; P[i] = v; }
  // @End [ZvVe6KNN]
  vector<ll> S(N), A(N), B(N);
  ll t = 1e8;
  REP(i, 0, N) S[P[i]] = i;
  A[0] = 1;
  B[0] = S[0] - A[0];
  REP(i, 1, N) {
    if (S[i] > S[i - 1]) {
      B[i] = B[i - 1] - 1;
      A[i] = S[i] - B[i];
    }else {
      A[i] = A[i - 1] + 1;
      B[i] = S[i] - A[i];
    }
  }
  ll x = B[N - 1] - 1;
  REP(i, 0, N) B[i] = B[i] - x;
  REPOUT(i, 0, N, A[i], " ");
  REPOUT(i, 0, N, B[i], " ");

  return 0;
}

