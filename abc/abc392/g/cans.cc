#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
#include <atcoder/convolution>
using namespace atcoder;
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
  // @InpVec(N, S) [Oo3zoLhK]
  auto S = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; S[i] = v; }
  // @End [Oo3zoLhK]
  ll vmax = *max_element(ALL(S));
  vector<ll> A(vmax + 1);
  REP(i, 0, N) A[S[i]] = 1;
  auto B = convolution_ll(A, A);
  ll ans = 0;
  REP(i, 0, vmax + 1) {
    if (A[i]) {
      ans += (B[2 * i] - 1) / 2;
    }
  }
  cout << ans << endl;
  return 0;
}

