#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(coordCompr)

// ---- inserted library file coordCompr.cc

struct CoordCompr {
  int size;            // the number of different original values
  map<ll, int> mp;     // map from an original value to a compressed value
  vector<ll> rev;      // vector of original values

  CoordCompr(vector<ll> vec) {
    sort(vec.begin(), vec.end());
    for (int i = 0; i < (int)vec.size(); i++) {
      if (i == 0 || vec.at(i-1) != vec.at(i)) {
	mp[vec.at(i)] = rev.size();
	rev.push_back(vec.at(i));
      }
    }
    size = rev.size();
  }

  // compress
  int c(ll x) { return mp.at(x); }

  // decompress
  ll d(int i) { return rev.at(i); }
};

// ---- end coordCompr.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  vector<ll> C(N);
  for (ll i = 0; i < N; i++) cin >> C[i];
  CoordCompr cc(C);
  vector<ll> rec(N);
  ll cur = 0;
  for (ll i = 0; i < K; i++) {
    ll x = cc.c(C[i]);
    if (rec[x] == 0) cur++;
    rec[x]++;
  }
  ll ans = cur;
  for (ll i = K; i < N; i++) {
    ll x = cc.c(C[i]);
    ll y = cc.c(C[i - K]);
    if (rec[y] == 1) cur--;
    rec[y]--;
    if (rec[x] == 0) cur++;
    rec[x]++;
    ans = max(ans, cur);
  }
  cout << ans << endl;

  return 0;
}

