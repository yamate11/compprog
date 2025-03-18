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

  ll H, W; cin >> H >> W;
  // @InpVec(H, S, type=string) [yWyJCgWS]
  auto S = vector(H, string());
  for (int i = 0; i < H; i++) { string v; cin >> v; S[i] = v; }
  // @End [yWyJCgWS]
  // @InpVec(H, T, type=string) [0R9cJUIj]
  auto T = vector(H, string());
  for (int i = 0; i < H; i++) { string v; cin >> v; T[i] = v; }
  // @End [0R9cJUIj]

  vector<string> SS(W), TT(W);
  REP(i, 0, W) {
    SS[i] = string(H, ' ');
    TT[i] = string(H, ' ');
    REP(j, 0, H) SS[i][j] = S[j][i];
    REP(j, 0, H) TT[i][j] = T[j][i];
  }

  sort(ALL(SS));
  sort(ALL(TT));
  if (SS == TT) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }

  return 0;
}

