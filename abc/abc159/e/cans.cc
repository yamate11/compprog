#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W, K; cin >> H >> W >> K;
  vector<vector<ll>> S(H, vector<ll>(W));
  for (ll i = 0; i < H; i++) {
    string s; cin >> s;
    for (ll j = 0; j < W; j++) {
      S.at(i).at(j) = s.at(j) - '0';
    }
  }
  ll ans = LLONG_MAX;
  for (ll x = 0; x < (1 << (H-1)); x++) {
    bool xFault = false;
    ll numBreak = 0;
    vector<ll> cnt(H);
    for (ll c = 0; c < W; c++) {
      ll rg = 0;
      vector<ll> thisCnt(H);
      for (ll r = 0; r < H; r++) {
	if (r > 0 && ((1 << (r-1)) & x)) rg++;
	if (S.at(r).at(c)) thisCnt.at(rg)++;
      }
      bool within = true;
      for (ll yy = 0; yy < H; yy++) {
	if (thisCnt.at(yy) > K) {
	  xFault = true;
	  break;
	}
	if (cnt.at(yy) + thisCnt.at(yy) > K) {
	  within = false;
	  break;
	}
      }
      if (xFault) break;
      if (within) {
	for (ll yy = 0; yy < H; yy++) cnt.at(yy) += thisCnt.at(yy);
      }else {
	numBreak++;
	for (ll yy = 0; yy < H; yy++) cnt.at(yy) = thisCnt.at(yy);
      }
    }
    if (xFault) continue;
    ll k = __builtin_popcountll(x);
    ans = min(ans, numBreak + k);
  }
  cout << ans << endl;

  return 0;
}

