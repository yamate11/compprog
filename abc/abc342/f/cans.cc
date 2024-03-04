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

  ll N, L, D; cin >> N >> L >> D;
  vector Q(L + D, 0.0), SQ(L + D + 1, 0.0);
  Q[0] = 1.0;
  SQ[1] = SQ[0] + Q[0];
  REP(i, 1, L + D) {
    if (i < D) Q[i] =  SQ[i]              / D;
    else       Q[i] = (SQ[i] - SQ[i - D]) / D;
    SQ[i + 1] = SQ[i] + Q[i];
  }
  vector R(L + D, 0.0);
  REP(i, L, L + D) R[i] = Q[i] - (SQ[i] - SQ[L]) / D;
  REP(i, N + 1, L + D) {
    R[0] += R[i];
    R[i] = 0;
  }
  vector SR(L + D + 1, 0.0); REP(i, 0, L + D) SR[i + 1] = SR[i] + R[i];
  vector P(N + 1, 0.0);
  P[N] = SR[N];
  double sum = P[N];
  REPrev(i, N - 1, 0) {
    P[i] = max(SR[i], sum / D);
    sum = sum + P[i];
    if (i + D <= N) sum = sum - P[i + D];
  }
  cout << P[0] << "\n";
  return 0;
}

