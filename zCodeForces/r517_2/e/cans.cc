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
  vector<ll> A(n);
  for (ll i = 0; i < n; i++) cin >> A[i];

  auto bruteforce = [](ll n, ll x) -> pair<bool, vector<vector<ll>>> {
    vector<ll> sets;
    for (ll g = 1; 2 * g < n; g++) {
      for (ll s = 0; s + 2 * g < n; s++) {
        sets.emplace_back((1LL << s) | (1LL << (s + g)) | (1LL << (s + 2*g)));
      }
    }
    ll sz = sets.size();
    ll y0 = -1;
    ll vmin = sz + 1;
    for (ll y = 0; y < (1LL << sz); y++) {
      ll t = 0;
      ll pc = __builtin_popcount(y);
      if (pc >= vmin) continue;
      for (ll i = 0; i < sz; i++) {
        if ((y > i) & 1) t = (t | sets[i]);
      }
      if (t == x) {
        vmin = pc;
        y0 = y;
      }
    }
    if (vmin <= sz) {
      vector<vector<ll>> ret;
      for (ll i = 0; i < sz; i++) {
        if (!((y0 >> i) & 1)) continue;
        ll t = sets[i];
        vector<ll> z;
        for (ll j = 0; j < n; j++) {
          if (!((t >> j) & 1)) continue;
          z.push_back(j);
        }
        assert(z.size() == 3);
        ret.push_back(move(z));
      }
      return {true, move(ret)};
    }else {
      return {false, move(ret)};
    }
  };



  return 0;
}

