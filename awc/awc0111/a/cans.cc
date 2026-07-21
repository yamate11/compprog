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

  ll N, M, K; cin >> N >> M >> K;
  // @InpGrid(N, M, S) [ENlmUqtj]
  auto S = vector(N, vector(M, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) { ll v; cin >> v; S[i][j] = v; }
  // @End [ENlmUqtj]

  ll ans = 0;
  REP(i, 0, N) {
    ll tot = 0;
    if (M <= 2) {
      tot = accumulate(ALL(S[i]), 0LL);
      if (tot / M < K) ans++;
    }else {
      ranges::sort(S[i]);
      tot = accumulate(S[i].begin() + 1, S[i].end() - 1, 0LL);
      if (tot / (M - 2) < K) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

