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

  auto judge = [&]() -> ll {
    ll N; cin >> N;
    // @InpVec(N, W, type=string) [MlvFoat3]
    auto W = vector(N, string());
    for (int i = 0; i < N; i++) { string v; cin >> v; W[i] = v; }
    // @End [MlvFoat3]

    set<string> ss;
    REP(i, 0, N) {
      string w = W[i];
      if (ss.contains(w)) return i % 2;
      ss.insert(w);
      if (i >= 1 and w[0] != W[i - 1].back()) return i % 2;
    }
    return -1;
  };
  ll j = judge();
  string ans;
  if (j < 0) ans = "DRAW";
  else if (j == 0) ans = "LOSE";
  else ans = "WIN";
  cout << ans << endl;

  return 0;
}

