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
  // @InpVec(N, A) [jtNWleYH]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [jtNWleYH]

  ll tot = accumulate(ALL(A), 0LL);

  vector tbl(N + 1, vector(N + 1, 0LL));
  REP(len, 1, N + 1) {
    REP(i, 0, N - len + 1) {
      ll a = tbl[i][len - 1];
      ll b = tbl[i + 1][len - 1];
      tbl[i][len] = max(A[i + len - 1] - a, A[i] - b);
    }
  }
  ll x = tbl[0][N];
  assert((tot + x) % 2 == 0);
  ll tak = (tot + x) / 2;
  ll aok = tot - tak;
  cout << tak << " " << aok << endl;

  return 0;
}

