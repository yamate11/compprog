#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  using sta = tuple<string, ll, ll>;
  vector<sta> nodes(n + 1);
  for (ll i = 1; i <= n; i++) {
    string s; cin >> s;
    if (s == "IN" || s == "NOT") {
      ll a; cin >> a;
      nodes[i] = sta(s, a, -1);
    }else {
      ll a, b; cin >> a >> b;
      nodes[i] = sta(s, a, b);
    }
  }
  vector<ll> orig(n + 1);
  auto dfs1 = [&](auto rF, ll nd) -> void {
    auto [op, a, b] = nodes[nd];
    if (op == "IN") {
      orig[nd] = a;
    }else if (op == "NOT") {
      rF(rF, a);
      orig[nd] = 1 - orig[a];
    }else {
      rF(rF, a);
      rF(rF, b);
      ll va = orig[a];
      ll vb = orig[b];
      if (op == "AND") orig[nd] = va & vb;
      else if (op == "OR") orig[nd] = va | vb;
      else if (op == "XOR") {
        if (va == vb) orig[nd] = 0;
        else orig[nd] = 1;
      }else assert(0);
    }
  };
  dfs1(dfs1, 1);
  ll val = orig[1];
  vector<ll> ans(n + 1, -1);
  auto dfs2 = [&](auto rF, ll nd, bool chg) -> void {
    auto [op, a, b] = nodes[nd];
    if (op == "IN") {
      if (chg) ans[nd] = 1 - val;
      else ans[nd] = val;
    } else if (op == "NOT") {
      rF(rF, a, chg);
    } else {
      if (!chg) {
        rF(rF, a, false);
        rF(rF, b, false);
      }else {
        if (op == "AND") {
          if (orig[a] == 0) rF(rF, b, false);
          else rF(rF, b, true);
          if (orig[b] == 0) rF(rF, a, false);
          else rF(rF, a, true);
        }
        else if (op == "OR") {
          if (orig[a] == 1) rF(rF, b, false);
          else rF(rF, b, true);
          if (orig[b] == 1) rF(rF, a, false);
          else rF(rF, a, true);
        }else {
          rF(rF, a, true);
          rF(rF, b, true);
        }
      }
      
    }
  };
  dfs2(dfs2, 1, true);
  for (ll i = 1; i <= n; i++) {
    if (ans[i] >= 0) {
      cout << ans[i];
    }
  }
  cout << endl;
  return 0;
}

