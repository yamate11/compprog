#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
#include <atcoder/convolution>
using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

constexpr int primeB = 998'244'353;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, A) [DriIwtAt]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [DriIwtAt]
  // @InpVec(N, B) [IKcKKS4f]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [IKcKKS4f]
  ll s = 0;
  REP(i, 0, N) s += A[i] + B[i];
  vector w(N, 0LL);
  REP(k, 0, 5) {
    vector va(N, 0LL);
    vector vb(2*N, 0LL);
    REP(i, 0, N) va[i] = (A[i] >> k) & 1;
    REP(i, 0, N) vb[i] = vb[N + i] = (B[N-1 - i] >> k) & 1;
    auto vc = convolution_ll(va, vb);
    REP(i, 0, N) w[i] += vc[N-1 + i] << k;
  }
  ll m = *min_element(ALL(w));
  cout << s - m << endl;

  return 0;
}

