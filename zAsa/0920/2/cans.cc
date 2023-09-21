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
  // @InpVec(H, S, type=string) [wvNjyVPD]
  auto S = vector(H, string());
  for (int i = 0; i < H; i++) { string v; cin >> v; S[i] = v; }
  // @End [wvNjyVPD]
  // @InpVec(H, T, type=string) [RP9vvvBj]
  auto T = vector(H, string());
  for (int i = 0; i < H; i++) { string v; cin >> v; T[i] = v; }
  // @End [RP9vvvBj]

  vector<string> CS(W), CT(W);
  REP(j, 0, W) REP(i, 0, H) {
    CS[j].push_back(S[i][j]);
    CT[j].push_back(T[i][j]);
  }
  sort(ALL(CS));
  sort(ALL(CT));
  cout << (CS == CT ? "Yes\n" : "No\n");

  return 0;
}

