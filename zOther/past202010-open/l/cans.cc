#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  vector<ll> H(N);
  for (ll i = 0; i < N; i++) cin >> H[i];
  map<ll, ll> EO, OE;
  for (ll i = 0; i < N-1; i++) {
    ll diff = H[i+1] - H[i];
    if (i % 2 == 0) EO[diff]++;
    else            OE[diff]++;
  }
  ll levEO = 0;
  ll levOE = 0;
  ll cumE = 0;
  ll cumO = 0;
  for (ll _q = 0; _q < Q; _q++) {
    ll tp; cin >> tp;
    if (tp == 1) {   // EVEN
      ll v; cin >> v;
      levOE -= v;
      levEO += v;
      cumE += v;
    }else if (tp == 2) { // ODD
      ll v; cin >> v;
      levOE += v;
      levEO -= v;
      cumO += v;
    }else if (tp == 3) {
      ll u, v; cin >> u >> v; u--;
      if (u % 2 == 0) {
	if (u-1 >= 0) {
	  ll pdiff = H[u] - H[u-1];
	  ll ndiff = pdiff + v;
	  OE[pdiff]--;
	  OE[ndiff]++;
	}
	if (u+1 < N) {
	  ll pdiff = H[u+1] - H[u];
	  ll ndiff = pdiff - v;
	  EO[pdiff]--;
	  EO[ndiff]++;
	}
      }else {
	if (u-1 >= 0) {
	  ll pdiff = H[u] - H[u-1];
	  ll ndiff = pdiff + v;
	  EO[pdiff]--;
	  EO[ndiff]++;
	}
	if (u+1 < N) {
	  ll pdiff = H[u+1] - H[u];
	  ll ndiff = pdiff - v;
	  OE[pdiff]--;
	  OE[ndiff]++;
	}
      }
      H[u] += v;
    }
    cout << EO[levEO] + OE[levOE] << "\n";
  }


  return 0;
}

