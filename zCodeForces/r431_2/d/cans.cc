#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, w, h; cin >> n >> w >> h;
#if DEBUG
  constexpr ll gsize = 30;
#else
  constexpr ll gsize = 200100;
#endif
  using sta = tuple<ll, ll, ll>;
  vector grp(gsize, vector<sta>());
  auto get_grp = [&](ll z) -> vector<sta>& { return grp[z + (gsize / 2)]; };
  for (ll i = 0; i < n; i++) {
    ll g, p, t; cin >> g >> p >> t; g--;
    get_grp(p - t).emplace_back(g, p, i);
  }
  using stb = pair<ll, ll>;
  vector<stb> ans(n);
  for (ll z = -gsize / 2; z < gsize / 2; z++) {
    vector<sta>& vec = get_grp(z);
    ll sz = vec.size();
    auto vec2 = vec;
    bool flag;
    auto cmp = [&](const sta& a, const sta& b) -> bool {
      const auto& [ga, pa, ia] = a;
      const auto& [gb, pb, ib] = b;
      if (ga != gb) return flag == (ga > gb);
      if (ga == 1) return pa > pb;
      return pa < pb;
    };
    flag = true;
    sort(vec.begin(), vec.end(), cmp);
    flag = false;
    sort(vec2.begin(), vec2.end(), cmp);
    for (ll i = 0; i < sz; i++) {
      const auto& [g1, p1, i1] = vec[i];
      const auto& [g2, p2, i2] = vec2[i];
      if (g2 == 0) ans[i1] = stb(p2, h);
      else         ans[i1] = stb(w, p2);
    }
  }
  for (ll i = 0; i < n; i++) {
    auto [x, y] = ans[i];
    cout << x << " " << y << "\n";
  }


  return 0;
}

