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
  // @InpVec(N, S, type=string) [Enqf4JnN]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [Enqf4JnN]

  ll big = 1e18;
  vector<ll> cnt(26, big);
  REP(i, 0, N) {
    vector<ll> cur(26, 0LL);
    REP(j, 0, ssize(S[i])) cur[S[i][j] - 'a']++;
    REP(j, 0, 26) cnt[j] = min(cnt[j], cur[j]);
  }
  string ans;
  REP(i, 0, 26) ans += string(cnt[i], 'a' + i);
  cout << ans << endl;

  return 0;
}

