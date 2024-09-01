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

  ll N, M; cin >> N >> M;
  // @InpVec(N, A) [9YOCmlQD]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [9YOCmlQD]

  auto D = A;
  REP(i, 0, N - 1) D[i + 1] += D[i];

  ll ans = 0;
  ll t = 0;
  vector<ll> B(M);
  REP(i, 0, N - 1) {
    t = (t + A[i]) % M;
    B[t]++;
  }
  ans += B[0];
  REP(st, 1, N) {
    ll t0 = D[st - 1] % M;
    t = (t + A[(N - 2 + st) % N]) % M;
    B[t]++;
    B[t0]--;
    ans += B[t0];
  }
  cout << ans << endl;

  return 0;
}

