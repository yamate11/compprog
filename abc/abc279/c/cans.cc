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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W; cin >> H >> W;
  // @InpVec(H, S, type=string) [jefn0q7l]
  auto S = vector(H, string());
  for (int i = 0; i < H; i++) { string v; cin >> v; S[i] = v; }
  // @End [jefn0q7l]
  // @InpVec(H, T, type=string) [NZtA6J7a]
  auto T = vector(H, string());
  for (int i = 0; i < H; i++) { string v; cin >> v; T[i] = v; }
  // @End [NZtA6J7a]
  vector<string> A(W, string(H, ' '));
  vector<string> B(W, string(H, ' '));
  REP(i, 0, H) REP(j, 0, W) {
    A[j][i] = S[i][j];
    B[j][i] = T[i][j];
  }
  sort(ALL(A));
  sort(ALL(B));
  if (A == B) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }

  return 0;
}

