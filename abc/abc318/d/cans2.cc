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

using ull = unsigned long long;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  auto D = vector(N, vector(N, 0LL));
  REP(i, 0, N - 1) {
    REP(j, 0, N - 1 - i) {
      ll d; cin >> d;
      D[i][i + 1 + j] = D[i + 1 + j][i] = d;
    }
  }
  ll ans = 0;
  auto dfs = [&](auto rF, ll rem, ll val) -> void {
    if (rem == 0) ans = max(ans, val);
    else {
      ll i = countr_zero(ull(rem));
      rem ^= (1LL << i);
      REP(j, i + 1, N) {
        if (rem >> j & 1) {
          rF(rF, rem ^ (1LL << j), val + D[i][j]);
        }
      }
    }
  };
  if (N % 2 == 0) {
    dfs(dfs, (1LL << N) - 1, 0);
  }else {
    ll mask = (1LL << N) - 1;
    REP(i, 0, N) {
      dfs(dfs, mask ^ (1LL << i), 0);
    }
  }
  cout << ans << endl;

  return 0;
}

