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
  // @InpVec(N, S, type=string) [2lltLO8t]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [2lltLO8t]

  ll big = 1e18;
  vector<ll> tbl_init(N + 1, big);
  vector<ll> tbl(N + 1, 0);
  REP(i, 0, N) {
    auto prev = move(tbl);
    tbl = tbl_init;
    ll right_white = 0;
    REP(j, 0, N) if (S[i][j] == '.') right_white++;
    ll left_black = 0;
    REP(j, 0, N + 1) {
      tbl[j] = left_black + right_white + prev[j];
      if (S[i][j] == '.') right_white--;
      else                left_black++;
    }
    REPrev(j, N - 1, 0) tbl[j] = min(tbl[j], tbl[j + 1]);
  }
  cout << tbl[0] << "\n";
  return 0;
}

