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
  auto count = [&](ll k) -> ll {
    ll ret = 0;
    ll i = 0;
    vector<bool> app(n + 1);
    while (i < n) {
      ll t = 0;
      vector<ll> rec;
      while (i < n) {
	if (!app[A[i]]) {
	  if (t == k) break;
	  t++;
	  app[A[i]] = true;
	  rec.push_back(A[i]);
	}
	i++;
      }
      ret++;
      for (ll x : rec) app[x] = false;
    }
    return ret;
  };
  vector<ll> ans(n + 1);
  auto calc = [&](auto rF, ll l, ll r) -> void {
    if (l + 1 == r) return;
    if (ans[l] == ans[r]) {
      for (ll i = l + 1; i < r; i++) ans[i] = ans[l];
      return;
    }
    ll mid = (l + r) / 2;
    ans[mid] = count(mid);
    rF(rF, l, mid);
    rF(rF, mid, r);
  };
  ans[1] = count(1);
  ans[n] = count(n);
  calc(calc, 1, n);
  for (ll i = 1; i <= n; i++) {
    if (i > 1) cout << " ";
    cout << ans[i];
  }
  cout << endl;

  return 0;
}

