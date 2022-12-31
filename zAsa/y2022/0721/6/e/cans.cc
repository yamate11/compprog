#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;

int main() {
  ll N, K; cin >> N >> K;
  vector<ll> S(N + 1);
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    S[i + 1] = S[i] + a - K;
  }
  using pll = pair<ll, ll>;
  tree<pll, null_type, less<pll>, rb_tree_tag,
       tree_order_statistics_node_update> ss;
  ll ans = 0;
  for (ll i = 0; i < N + 1; i++) {
    pll p(S[i], i);
    ans += ss.order_of_key(p);
    ss.insert(p);
  }
  cout << ans << endl;
  return 0;
}

