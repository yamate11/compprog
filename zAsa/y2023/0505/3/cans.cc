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
  // @InpVec(N, W, type=string) [KZHfGwDl]
  auto W = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; W[i] = v; }
  // @End [KZHfGwDl]
  set<string> ss;
  REP(i, 0, N) {
    if (ss.find(W[i]) != ss.end() or (i > 0 and W[i - 1].back() != W[i][0])) {
      if (i % 2 == 0) cout << "LOSE\n";
      else cout << "WIN\n";
      return 0;
    }
    ss.insert(W[i]);
  }
  cout << "DRAW\n";
  return 0;
}

