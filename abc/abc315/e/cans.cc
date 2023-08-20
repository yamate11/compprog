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
  vector<ll> C(N);
  vector P(N, vector<ll>());
  REP(i, 0, N) {
    cin >> C[i];
    P[i].resize(C[i]);
    REP(j, 0, C[i]) {
      ll p; cin >> p; p--;
      P[i][j] = p;
    }
  }
  vector<ll> ans;
  vector<ll> checked(N);
  auto dfs = [&](auto rF, ll nd) -> void {
    for (ll p : P[nd]) {
      if (not checked[p]) {
        rF(rF, p);
        checked[p] = true;
        ans.push_back(p);
      }
    }
  };
  dfs(dfs, 0);
  REPOUT(i, 0, SIZE(ans), ans[i] + 1, " ");

  return 0;
}

