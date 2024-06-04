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

  ll N, K; cin >> N >> K;
  // @InpVec(N, A) [REFVbDPg]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [REFVbDPg]
  ll sum = 0;
  REP(i, 0, N) sum += A[i];
  if (K > 0) {
    cout << "Yes\n";
    sort(ALL(A));
    REPOUT(i, 0, N, A[i], " ");
    return 0;
  }else {
    if (sum >= K) {
      sort(ALL(A), greater<ll>());
      cout << "Yes\n";
      REPOUT(i, 0, N, A[i], " ");
    }else {
      cout << "No\n";
    }
  }

  return 0;
}

