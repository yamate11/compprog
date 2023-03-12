#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(f:updMaxMin)
// --> f:updMaxMin
// ---- inserted function updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end updMaxMin
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  auto W = vector(N, vector(N, 0LL));
  for(ll i = 0; i < N; i++) {
    for (ll j = 0; j < N; j++) cin >> W[i][j];
  }

  ll pow = 1LL << N;
  vector<ll> grpsum(pow);
  for (ll x = 1; x < pow; x++) {
    ll t = 63 - __builtin_clzll(x);
    ll y = x & ~(1LL << t);
    ll s = grpsum[y];
    for (ll i = 0; i < t; i++) { 
      if ((y >> i) & 1) { s += W[t][i]; }
    }
    grpsum[x] = s;
  }
  
  ll univ = pow - 1;
  vector<ll> altscore(pow);
  for (ll x = 1; x < pow; x++) {
    ll s = K + grpsum[x];
    ll y = x & (x - 1);
    while (y > 0) {
      ll z = x & ~y;
      updMax(s, altscore[y] + altscore[z]);
      y = x & (y - 1);
    }
    altscore[x] = s;
  }
  cout << altscore[univ] - grpsum[univ] << endl;

  return 0;
}

