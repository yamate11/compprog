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
  vector A(N, vector<ll>());
  REP(i, 0, N) {
    ll l; cin >> l;
    REP(j, 0, l) {
      ll a; cin >> a;
      A[i].push_back(a);
    }
  }
  // @InpVec(N, C) [bRuAEyDR]
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
  // @End [bRuAEyDR]
  K--;
  REP(i, 0, N) {
    if (K < C[i] * ssize(A[i])) {
      ll x = K % ssize(A[i]);
      cout << A[i][x] << endl;
      return 0;
    }
    K -= C[i] * ssize(A[i]);
  }

  return 0;
}

