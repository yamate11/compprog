#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> nodeCol(N);
  for (ll i = 0; i < N; i++) cin >> nodeCol.at(i);
  vector<vector<ll>> nbr(N);
  for (ll i = 0; i < N-1; i++) {
    ll a, b; cin >> a >> b; a--; b--;
    nbr.at(a).push_back(b);
    nbr.at(b).push_back(a);
  }
  vector<ll> nPath(N+1);
  vector<stack<ll>> nNode(N+1);
  for (ll col = 1; col <= N; col++) nNode.at(col).push(0);
  auto dfs = [&](const auto& recF, ll n, ll p) -> ll {
    ll col = nodeCol.at(n);
    auto& st = nNode.at(col);
    ll cnt = 1; // self;
    for (ll k : nbr.at(n)) {
      if (k == p) continue;
      st.push(0);
      ll nSub = recF(recF, k, n);
      cnt += nSub;
      ll e = nSub - st.top(); st.pop();
      nPath.at(col) += e * (e+1) / 2;
    }
    st.top() += cnt;
    return cnt;
  };
  dfs(dfs, 0, -1);
  for (ll col = 1; col <= N; col++) {
    ll e = N - nNode.at(col).top();
    nPath.at(col) += e * (e+1) / 2;
    cout << N * (N+1) / 2 - nPath.at(col) << "\n";
  }
  return 0;
}

