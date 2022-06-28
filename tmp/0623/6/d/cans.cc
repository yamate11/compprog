#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

ll H, W;
vector<string> S;
vector<vector<bool>> visited;

struct judge {
  ll br0;
  ll br1;
  ll cnt;
  void dfs(ll i, ll j) {
    if (S[i][j] == '.' or visited[i][j]) return 0;
    visited[i][j] = true;
    br0 = min(br0, i);
    br1 = max(br1, i);
    cnt++;
    for (ll di = -1; di <= 1; di++)
      for (ll dj = -1; dj <= 1; dj++)
        dfs(i + di, j + dj);
  };
  ll run(ll i, ll j) {
    br0 = br1 = i; cnt = 0;
    dfs(i, j);
    ll exp = (br1 + 1 - br0) / 5;
    n /= exp * exp;
    return n == 12 ? 0 : n == 16 ? 1 : 2;
  }
};

int main() {
  vector<ll> ans(3);
  cin >> H >> W;
  S.resize(H);
  for (ll i = 0; i < H; i++) cin >> S[i];
  visited.resize(H, vector<bool>(W));
  for (ll i = 1; i+1 < H; i++)
    for (ll j = 1; j+1 < W; j++)
      if (S[i][j] == 'o' and not visited[i][j]) ans[judge().run(i, j)]++;
  for (ll i = 0; i < 3; i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}

