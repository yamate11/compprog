#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, X; cin >> N >> X;
  vector<ll> A(N + 1); REP2(i, 1, N + 1) cin >> A[i];
  vector<bool> visited(N + 1);
  ll cnt = 0;
  auto dfs = [&](auto rF, ll i) -> void {
    if (visited[i]) return;
    visited[i] = true;
    cnt++;
    rF(rF, A[i]);
  };
  dfs(dfs, X);
  cout << cnt << endl;

  return 0;
}

