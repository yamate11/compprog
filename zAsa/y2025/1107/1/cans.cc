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

  // @InpVec(8, S, type=string) [8CDRJ8qV]
  auto S = vector(8, string());
  for (int i = 0; i < 8; i++) { string v; cin >> v; S[i] = v; }
  // @End [8CDRJ8qV]

  vector vec(8, vector(8, false));
  REP(i, 0, 8) REP(j, 0, 8) {
    if (S[i][j] == '#') {
      REP(ii, 0, 8) vec[ii][j] = true;
      REP(jj, 0, 8) vec[i][jj] = true;
    }
  }
  ll ans = 0;
  REP(i, 0, 8) REP(j, 0, 8) if (not vec[i][j]) ans++;
  cout << ans << endl;

  return 0;
}

