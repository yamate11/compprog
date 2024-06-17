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
  // @InpVec(N, PP, dec=1) [YgPcm9VT]
  auto PP = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; PP[i] = v; }
  // @End [YgPcm9VT]
  vector<ll> P(N);
  REP(i, 0, N) P[PP[i]] = i;

  vector<ll> A(N), B(N);
  A[0] = 1;
  B[0] = 0;
  REP(i, 1, N) {
    A[i] = A[i - 1] + 1;
    B[i] = B[i - 1] - 1;
    if (P[i - 1] < P[i]) A[i] += P[i] - P[i - 1];
    else B[i] -= P[i - 1] - P[i];
  }
  ll e = -B[N - 1] + 1;
  REP(i, 0, N) B[i] += e;
  REPOUT(i, 0, N, A[i], " ");
  REPOUT(i, 0, N, B[i], " ");

  return 0;
}

