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
  // @InpVec(M, D) [mFwoI3XJ]
  auto D = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; D[i] = v; }
  // @End [mFwoI3XJ]
  vector<ll> A(N + 1);
  vector<ll> revA(N + 1);
  REP(i, 0, N + 1) {
    A[i] = i;
    revA[i] = i;
  }
  REP(i, 0, M) {
    ll n = D[i];
    ll m = A[0];
    ll pos = revA[n];
    A[pos] = m;
    A[0] = n;
    revA[m] = pos;
    revA[n] = 0;
  }
  REPOUT(i, 1, N + 1, A[i], "\n");

  return 0;
}

