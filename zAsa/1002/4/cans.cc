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
  ll N, K; cin >> N >> K;
  auto A = vector(N, 0LL);
  REP(i, 0, N) cin >> A[i];
  sort(ALL(A), greater<ll>());
  A.push_back(0);
  ll sat = 0;
  REP(i, 0, SIZE(A) - 1) {
    ll k = A[i] - A[i + 1];
    ll m = min(K / (i + 1), k);
    ll a = A[i] - m + 1;
    sat += (i + 1) * (A[i] + a) * m / 2;
    if (k > m) {
      sat += (K % (i + 1)) * (a - 1);
      break;
    }
    K -= (i + 1) * k;
  }
  cout << sat << endl;
  return 0;
}

