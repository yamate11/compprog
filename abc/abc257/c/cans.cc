#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  string S; cin >> S;
  vector<ll> W(N); REP(i, N) cin >> W[i];
  map<ll, ll> adult, child;
  REP(i, N) {
    if (S[i] == '0') {
      child[W[i]]++;
      adult[W[i]] += 0;
    }else {
      child[W[i]] += 0;
      adult[W[i]] ++;
    }
  }
  ll diff = 0;
  ll w0 = -1;
  ll vmax = 0;
  for (auto [w, nc] : child) {
    ll na = adult[w];
    diff += nc - na;
    if (vmax < diff) {
      vmax = diff;
      w0 = w;
    }
  }
  ll ans = 0;
  for (auto [w, nc] : child) {
    ll na = adult[w];
    if (w <= w0) ans += nc;
    else ans += na;
  }
  cout << ans << endl;

  return 0;
}

