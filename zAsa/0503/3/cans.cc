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

  ll N, X; cin >> N >> X;
  vector<ll> L(N);
  vector A(N, vector<ll>());
  REP(i, 0, N) {
    cin >> L[i];
    REP(j, 0, L[i]) {
      ll a; cin >> a;
      A[i].push_back(a);
    }
  }

  ll ans = 0;
  auto dfs = [&](auto rF, ll k, ll s) -> void {
    if (k == N) {
      if (s == X) ans++;
      return;
    }
    REP(i, 0, L[k]) {
      ll t;
      bool b = __builtin_smulll_overflow(s, A[k][i], &t);
      if (not b and t <= X) rF(rF, k + 1, t);
    }
  };
  dfs(dfs, 0, 1);
  cout << ans << endl;

  return 0;
}

