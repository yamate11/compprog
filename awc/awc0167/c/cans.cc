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

  ll N, M, K; cin >> N >> M >> K;
  // @InpVec(M - 1, D) [QlYzBFbM]
  auto D = vector(M - 1, ll());
  for (int i = 0; i < M - 1; i++) { ll v; cin >> v; D[i] = v; }
  // @End [QlYzBFbM]

  if (N == 1) {
    cout << "0\n";
    return 0;
  }

  vector<ll> A(M, 0LL);
  REP(i, 0, M - 1) A[i + 1] = A[i] + D[i];
  ll j = 0;
  REP(i, 1, N) {
    ll k = ranges::lower_bound(A, A[j] + K) - A.begin();
    if (k <= M - 1) j = k;
    else {
      cout << "-1\n";
      return 0;
    }
  }
  cout << A[M - 1] << "\n";

  return 0;
}

