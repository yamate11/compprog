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
  // @InpVec(N, A) [meiFL5NY]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [meiFL5NY]
  enum tp {GOLD, SILVER};
  tp cur = GOLD;
  auto ans = vector(N, 0LL);
  REP(i, 0, N - 1) {
    if (A[i] < A[i + 1] and cur == SILVER) {
      ans[i] = 1;
      cur = GOLD;
    }
    else if (A[i] > A[i + 1] and cur == GOLD) {
      ans[i] = 1;
      cur = SILVER;
    }
  }
  if (cur == SILVER) ans[N - 1] = 1;
  REPOUT(i, 0, SIZE(ans), ans[i], " ");

  return 0;
}

