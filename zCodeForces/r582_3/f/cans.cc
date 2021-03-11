#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, k; cin >> n >> k;
  vector<ll> p(n), q(n);
  for (ll i = 0; i < n; i++) {
    ll z; cin >> z; z--;
    p[i] = z;
  }
  for (ll i = 0; i < n; i++) {
    ll z; cin >> z; z--;
    q[i] = z;
  }
  vector<ll> app(n);
  vector<ll> st;
  {
    ll th = 0;
    ll i = 0;
    while (th < n) {
      ll cnt = 0;
      ll len = 0;
      while (i < n) {
	if (app[p[i]] == 0) cnt++;
	app[p[i]] ++;
	if (app[q[i]] == 0) cnt++;
	app[q[i]] ++;
	len++;
	i++;
	if (len == cnt) break;
      }
      th += len;
      st.push_back(th);
    }
  }
  ll m = st.size();
  if (m < k) {
    cout << "NO\n";
    return 0;
  }
  ll c = 'a';
  ll j = 0;
  string ans(n, '.');
  for (ll i = 0; i < m; i++) {
    for (; j < st[i]; j++) ans[p[j]] = c;
    if (c < 'z') c++;
  }
  cout << "YES" << endl << ans << endl;

  return 0;
}

