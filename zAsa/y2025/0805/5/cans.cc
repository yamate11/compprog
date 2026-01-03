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
  // @InpVec(N, S, type=string) [LL3c8DOt]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [LL3c8DOt]
  sort(ALL(S));

  ll ans = 0;
  auto dfs = [&](auto rF, ll start, ll len, ll k) -> void {
    if (len <= 1) return;
    ll i = start;
    while (ssize(S[i]) <= k) i++;
    while (i < start + len) {
      char c = S[i][k];
      ll i0 = i;
      while (i < start + len and S[i][k] == c) i++;
      ll n = i - i0;
      ans += n * (n - 1) / 2;
      rF(rF, i0, n, k + 1);
    }
  };
  dfs(dfs, 0, N, 0);
  cout << ans << endl;

  return 0;
}

