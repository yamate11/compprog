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
  // @InpVec(N, A) [lnws8W5z]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [lnws8W5z]
  vector<ll> tbl(N + 1);
  tbl[0] = 0;
  tbl[1] = abs(A[1] - A[0]);
  REP(i, 2, N) {
    tbl[i] = min(tbl[i - 2] + abs(A[i] - A[i - 2]),
                 tbl[i - 1] + abs(A[i] - A[i - 1]));
  }
  cout << tbl[N - 1] << endl;

  return 0;
}

