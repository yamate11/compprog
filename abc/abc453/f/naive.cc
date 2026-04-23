#include<bits/stdc++.h>
namespace {
#pragma GCC diagnostic ignored "-Wunused-function"
#include<atcoder/all>
#pragma GCC diagnostic warning "-Wunused-function"
using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    VVI to(n);
    rep(_, n - 1) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      to[u].emplace_back(v);
      to[v].emplace_back(u);
    }
    VI c(k);
    rep(i, k) cin >> c[i];
    if (n == 2) {
      int cmx = max_element(all(c)) - c.begin();
      if (c[cmx] == 1) {
        cout << -1 << '\n';
        continue;
      }
      rep(i, n) cout << cmx + 1 << " \n"[i + 1 == n];
      continue;
    }
    VI ls;
    auto dfs = [&](auto&& self, int u, int p) -> void {
      if (to[u].size() == 1) {
        ls.emplace_back(u);
        return;
      }
      for (int v : to[u]) if (v != p) self(self, v, u);
    };
    {
      int r = 0;
      while (to[r].size() == 1) r++;
      dfs(dfs, r, -1);
    }
    int sz = ls.size();
    vector<P> use;
    vector<int> ord(k);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
      return c[i] > c[j];
    });
    int left = sz + 1;
    for (int i : ord) {
      int t = min(c[i], left);
      if (t >= 2) {
        use.emplace_back(i, t);
        left -= t;
      }
    }
    if (left >= 2) {
      cout << -1 << '\n';
      continue;
    }
    if (left == 0) {
      ls.insert(ls.begin(), 1, to[ls[0]][0]);
    }
    {
      int sz = use.size();
      rep(idx, sz) {
        auto& [i, t] = use[idx];
        t--;
        use.emplace_back(i, 1);
      }
    }
    VI ans(n, -1);
    for (int l : ls) {
      if (use.back().second == 0) use.pop_back();
      int col = use.back().first;
      use.back().second--;
      c[col]--;
      ans[l] = col;
    }
    int col = 0;
    rep(i, n) if (ans[i] == -1) {
      while (!c[col]) col++;
      ans[i] = col;
      c[col]--;
    }
    rep(i, n) cout << ans[i] + 1 << " \n"[i + 1 == n];
  }
}
