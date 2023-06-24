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

  ll N; cin >> N;
  vector<bool> A(N);
  ll a, b; cin >> a >> b; a--; b--;
  A[a] = true;
  A[b] = true;
  ll K; cin >> K;
  // @InpVec(K, P, dec=1) [1Mq5J8aI]
  auto P = vector(K, ll());
  for (int i = 0; i < K; i++) { ll v; cin >> v; v -= 1; P[i] = v; }
  // @End [1Mq5J8aI]
  REP(i, 0, K) {
    if (A[P[i]]) {
      cout << "NO\n";
      return 0;
    }
    A[P[i]] = true;
  }
  cout << "YES\n";
  return 0;
}

