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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  int N; cin >> N;
  N *= 2;
  vector A(N, vector(N, 0));
  for (int i = 0; i < N; i++) for (int j = i + 1; j < N; j++) cin >> A[i][j];
  unsigned ans = 0;
  auto dfs = [&](auto rF, unsigned s, unsigned score) -> void {
    int i = countr_one(s);
    if (i == N) ans = max(ans, score);
    else {
      s |= 1 << i;
      REP(j, i + 1, N) if (not (s >> j & 1)) rF(rF, s | (1 << j), score ^ A[i][j]);
    }
  };
  dfs(dfs, 0, 0);
  cout << ans << endl;
  return 0;
}

