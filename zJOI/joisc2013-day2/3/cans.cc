#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<ll> P(N), Q(N), R(M), S(M);
  vector<vector<ll>> jcld(N), icld(N);
  ll root_j, root_i;
  for (ll i = 0; i < N; i++) {
    ll p, q; cin >> p >> q; p--; q--;
    P[i] = p;
    Q[i] = q;
    if (p < 0) root_j = p;
    else jcld[p].push_back(i);
    if (q < 0) root_i = q;
    else icld[q].push_back(i);
  }
  vector<vector<ll>> ldcor(N, vector<ll>());
  for (ll i = 0; i < M; i++) {
    cin >> r >> s; r--; s--;
    R[i] = r;
    S[i] = s;
    ldcor[s].push_back(r);
  }
  vector<vector<bool>> desc(N, vector<bool>(N, false));
  auto dfs1 = [&](auto rF, ll n) {
    for (ll m : icld[n]) {
      rF(rF, m);
      for (ll i = 0; i < N; i++) desc[n][i] = desc[n][i] || desc[m][i];
      desc[n][m] = true;
    }
  };
  dfs1(dfs1, root_i);
  


  return 0;
}

