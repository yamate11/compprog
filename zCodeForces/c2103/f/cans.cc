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

void test() {
  string S; cin >> S;
  ll N = ssize(S);
  vector<string> ans(N, string(N, ' '));
  REP(i, 0, N) {
    bool cur = S[i] - '0';
    ans[i][i] = '0' + cur;
    REP(j, i + 1, N) {
      cur = not (cur or (S[j] - '0'));
      ans[i][j] = '0' + cur;
    }
  }
  REP(i, 0, N) cout << ans[i] << "\n";
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  test();
  return 0;

  auto solve = [&]() -> void {
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

