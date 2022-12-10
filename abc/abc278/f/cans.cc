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

  ll N; cin >> N;
  vector<string> S(N);
  REP(i, 0, N) cin >> S[i];
  vector nbr(26, vector<pll>());
  REP(i, 0, N) {
    ll c = S[i][0] - 'a';
    ll d = S[i][SIZE(S[i]) - 1] - 'a';
    nbr[c].emplace_back(i, d);
  }
  vector tbl(1LL << N, vector(26, -1LL));
  // 0 ... Player win; 1 ... Opponent win
  auto judge = [&](auto rF, ll x, ll c) -> ll {
    ll& ret = tbl[x][c];
    if (ret < 0) {
      for (auto [i, d] : nbr[c]) {
        if (not (x >> i & 1)) {
          ll b = rF(rF, x | (1LL << i), d);
          if (b == 1) {
            ret = 0;
            break;
          }
        }
      }
      if (ret < 0) ret = 1;
    }
    return ret;
  };
  REP(i, 0, N) {
    ll c = S[i][0] - 'a';
    if (judge(judge, 0, c) == 0) {
      cout << "First\n";
      return 0;
    }
  }
  cout << "Second\n";

  return 0;
}

