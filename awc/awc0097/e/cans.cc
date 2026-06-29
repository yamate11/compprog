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
  // @InpVec(N, H) [VZYCWEfm]
  auto H = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; H[i] = v; }
  // @End [VZYCWEfm]

  REP(i, 0, N) H[i] += (K - 1) * i;
  if (H[0] > H[N - 1]) {
    cout << -1 << endl;
    return 0;
  }

  vector<ll> A;
  REP(i, 1, N - 1) {
    if (H[0] <= H[i] and H[i] <= H[N - 1]) A.push_back(H[i]);
  }
  ll sz = ssize(A);
  vector<ll> B;
  REP(i, 0, sz) {
    ll k = lower_bound(ALL(B), A[i] + 1) - B.begin();
    if (k == ssize(B)) B.push_back(A[i]);
    else B[k] = A[i];
  }
  cout << N - (ssize(B) + 2) << endl;
  return 0;
}

