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

  ll H, W; cin >> H >> W;
  auto encR = [&](ll r) -> ll { return r; };
  auto encC = [&](ll c) -> ll { return H + c; };
  auto decRC = [&](ll f) -> pair<bool, ll> {
    if (f < H) return {false, f};
    else       return {true, f - H};
  };
  vector<vector<ll>> nbr(H + W);
  vector<bool> rows(H), cols(W);
  ll exRows = 0, exCols = 0;
  for (ll r = 0; r < H; r++) {
    string s; cin >> s;
    for (ll c = 0; c < W; c++) {
      if (s[c] == 'R') {
        nbr[encR(r)].push_back(encC(c));
        nbr[encC(c)].push_back(encR(r));
        if (!cols[c]) {
          exCols++;
          cols[c] = true;
        }
        if (!rows[r]) {
          exRows++;
          rows[r] = true;
        }
      }
    }
  }
  bool rootDir = H - exRows > W - exCols;
  vector<bool> visited(H + W);
  using sta = tuple<bool, ll, ll>;
  vector<sta> ans;
  auto dfs = [&](auto rF, ll nd, ll pt) -> void {
    if (visited[nd]) return;
    auto [isCol, x] = decRC(nd);
    visited[nd] = true;
    bool hasChild = false;
    for (ll f : nbr[nd]) {
      if (f == pt) continue;
      hasChild = true;
      rF(rF, f, nd);
    }
    if (pt < 0) {
      if (hasChild) {
        auto [b, xx, yy] = ans.back(); ans.pop_back();
        ans.emplace_back(rootDir, xx, yy);
      }
    }else {
      auto [_dum, y] = decRC(pt);
      if (isCol) ans.emplace_back(true, y, x);
      else       ans.emplace_back(false, x, y);
    }
  };
  for (ll i = 0; i < H + W; i++) {
    dfs(dfs, i, -1);
  }
  cout << ans.size() << "\n";
  for (auto [b, r, c] : ans) {
    cout << (b ? "Y " : "X ") << r + 1 << " " << c + 1 << "\n";
  }
  return 0;
}

