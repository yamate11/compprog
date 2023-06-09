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

  ll R, C; cin >> R >> C; R--; C--;
  // @InpGrid(2, 2, A) [KcQC81d6]
  auto A = vector(2, vector(2, ll()));
  for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [KcQC81d6]
  cout << A[R][C] << endl;

  return 0;
}

