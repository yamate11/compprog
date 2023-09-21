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
  // @InpVec(N, W, type=string) [Cc10MEGT]
  auto W = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; W[i] = v; }
  // @End [Cc10MEGT]
  set<string> ws;
  REP(i, 0, N) {
    if (i > 0) {
      if (ws.contains(W[i])) {
        cout << "No\n";
        return 0;
      }
      if (W[i - 1].back() != W[i][0]) {
        cout << "No\n";
        return 0;
      }
    }
    ws.insert(W[i]);
  }
  cout << "Yes\n";
  return 0;
}

