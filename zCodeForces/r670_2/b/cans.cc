#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll N; cin >> N;
    vector<ll> pos, neg;
    for (ll i = 0; i < N; i++) {
      ll a; cin >> a;
      if (a >= 0) pos.push_back(a);
      else neg.push_back(-a);
    }
    sort(pos.begin(), pos.end(), greater<ll>());
    sort(neg.begin(), neg.end(), greater<ll>());
    if (N == 5) {
      ll x = 1;
      for (ll t : pos) x *= t;
      for (ll t : neg) x *= -t;
      cout << x << "\n";
      return;
    }
    if (pos.empty()) {
      ll x = 1;
      for (ll i = 0; i < 5; i ++) x *= -neg[N-1 - i];
      cout << x << "\n";
      return;
    }
    ll p = 0, q = 0;
    ll x = pos[p]; p++;
    for (ll z__ = 0; z__ < 2; z__++) {
      if (p + 2 > (ll)pos.size()) {
	x *= neg[q] * neg[q+1];
	q += 2;
      }else if (q + 2 > (ll)neg.size()) {
	x *= pos[p] * pos[p+1];
	p += 2;
      }else {
	ll y = pos[p] * pos[p+1];
	ll z = neg[q] * neg[q+1];
	if (y >= z) {
	  x *= y;
	  p += 2;
	}else {
	  x *= z;
	  q += 2;
	}
      }
    }
    cout << x << "\n";

  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

