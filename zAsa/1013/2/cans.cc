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

  ll N, M; cin >> N >> M;

  vector A(N, 0LL);
  auto dfs = [&](auto rF, ll i) -> void {
    if (i == N) {
      REPOUT(j, 0, N, A[j] + 1, " ");
      return;
    }
    ll s = i == 0 ? 0 : A[i - 1] + 1;
    REP(v, s, M) {
      A[i] = v;
      rF(rF, i + 1);
    }
  };
  dfs(dfs, 0);

  return 0;
}

