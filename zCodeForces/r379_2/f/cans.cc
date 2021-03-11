#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll lim = 40;

  auto solve = [&]() -> bool {
    ll n; cin >> n;
    vector<ll> B(n), C(n);
    for (ll i = 0; i < n; i++) cin >> B[i];
    for (ll i = 0; i < n; i++) cin >> C[i];
    ll s = 0;
    for (ll i = 0; i < n; i++) s += B[i] + C[i];
    if (s % (2 * n) != 0) return false;
    ll sum = s / (2 * n);
    vector<ll> ans(n);
    for (ll i = 0; i < n; i++) {
      ll z = B[i] + C[i] - sum;
      if (z < 0 || z % n != 0) return false;
      ans[i] = z / n;
    }
    vector<ll> chk(lim);
    for (ll i = 0; i < n; i++) {
      ll a = ans[i];
      ll j = 0;
      while (a > 0) {
	if (a % 2 == 1) chk[j] += (1LL << j);
	a /= 2;
	j++;
      }
    }
    for (ll i = 0; i < n; i++) {
      ll bb = 0;
      ll cc = 0;
      for (ll j = 0; j < lim; j++) {
	ll t = 1LL << j;
	if (ans[i] & t) {
	  bb += chk[j];
	  cc += t * n;
	}else {
	  cc += chk[j];
	}
      }
      if (!(bb == B[i] && cc == C[i])) return false;
    }

    for (ll i = 0; i < n; i++) {
      if (i > 0) cout << " ";
      cout << ans[i];
    }
    cout << endl;
    return true;
  };

  if (!solve()) {
    cout << -1 << endl;
  }

  return 0;
}

