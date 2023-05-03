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

  ll N, K; cin >> N >> K;
  // @InpVec(N, A) [zvzbGWN7]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [zvzbGWN7]

  REP(k, 0, K) {
    vector<ll> C(N + 1);
    bool cont = false;
    REP(i, 0, N) {
      ll lo = max(0LL, i - A[i]);
      ll hi = min(N, i + A[i] + 1);
      if (0 < lo or hi < N) cont = true;
      C[lo]++;
      C[hi]--;
    }
    ll a = 0;
    REP(i, 0, N) {
      a += C[i];
      A[i] = a;
    }
    if (not cont) break;
  }
  REPOUT(i, 0, N, A[i], " ");

  return 0;
}

