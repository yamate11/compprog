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
  // @InpVec(N, S, type=string) [1Y8SgNTL]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [1Y8SgNTL]

  auto cnt = [&](ll x, ll y, ll dx, ll dy, char c) -> ll {
    ll ret = 0;
    REP(i, 0, N) {
      if (S[x + i * dx][y + i * dy] == c) ret++;
    }
    return ret;
  };

  ll ans = 0;
  REP(i, 0, N) {
    if (cnt(i, 0, 0, 1, 'A') == N - 1 and (cnt(i, 0, 0, 1, '.') == 1)) ans++;
    if (cnt(0, i, 1, 0, 'A') == N - 1 and (cnt(0, i, 1, 0, '.') == 1)) ans++;
  }
  if (cnt(0, 0, 1, 1, 'A') == N - 1 and cnt(0, 0, 1, 1, '.') == 1) ans++;
  if (cnt(0, N - 1, 1, -1, 'A') == N - 1 and cnt(0, N - 1, 1, -1, '.') == 1) ans++;
  cout << ans << endl;


  return 0;
}

