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
  using v_t = pair<ll, ll>;
  set<v_t> zeroes;
  set<v_t, greater<v_t>> ones;
  for (ll i = 0; i < n; i++) {
    ll w; cin >> w;
    zeroes.emplace(w, i);
  }
  string s; cin >> s;
  assert((ll)s.size() == 2*n);
  vector<ll> ans;
  for (ll i = 0; i < 2*n; i++) {
    if (s[i] == '0') {
      auto it = zeroes.begin();
      ones.insert(*it);
      ans.push_back(it->second);
      zeroes.erase(it);
    }else if (s[i] == '1') {
      auto it = ones.begin();
      ans.push_back(it->second);
      ones.erase(it);
    }
  }
  for (ll i = 0; i < 2*n; i++) {
    if (i > 0) cout << " ";
    cout << ans[i] + 1;
  }
  cout << "\n";


  return 0;
}

