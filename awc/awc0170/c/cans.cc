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

  ll N; cin >> N;
  // @InpVec(N, A) [clGpREbX]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [clGpREbX]
  ll tot = accumulate(ALL(A), 0LL);
  ll H = tot / 2;
  vector<bool> tbl(H + 1, false);
  tbl[0] = true;
  REP(i, 0, N) {
    REPrev(j, H, 0) if (tbl[j]) {
      if (j + A[i] <= H) tbl[j + A[i]] = true;
    }
  }
  REPrev(j, H, 0) {
    if (tbl[j]) {
      cout << tot - j - j << "\n";
      return 0;
    }
  }
  assert(0);

  return 0;
}

