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

  ll H, W; cin >> H >> W;
  ll N; cin >> N;
  // @InpVec(N, A) [PJmSVMz5]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [PJmSVMz5]
  auto ans = vector(H, vector(W, 0LL));
  ll p = 0;
  ll q = 0;
  REP(i, 0, N) {
    REP(j, 0, A[i]) {
      ans[p][q] = i;
      if (p % 2 == 0) {
        q++;
        if (q == W) {
          q = W - 1;
          p++;
        }
      }else {
        q--;
        if (q == -1) {
          q = 0;
          p++;
        }
      }
    }
  }
  REP(i, 0, H) {
    REPOUT(j, 0, W, ans[i][j] + 1, " ");
  }
  

  return 0;
}

