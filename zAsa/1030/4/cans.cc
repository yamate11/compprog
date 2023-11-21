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
  vector vec(10, vector(10, 0LL));
  REP(i, 1, N + 1) {
    ll a = to_string(i)[0] - '0';
    ll b = i % 10;
    vec[a][b]++;
  }
  ll ans = 0;
  REP(i, 0, 10) REP(j, 0, 10) ans += vec[i][j] * vec[j][i];
  cout << ans << endl;

  return 0;
}

