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

  ll N, W; cin >> N >> W;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  vector<bool> seen(W + 1);
  ll ans = 0;
  REP(i, N) {
    ll s = A[i];
    if (s <= W and not seen[s]) {
      ans++;
      seen[s] = true;
    }
    REP2(j, i + 1, N) {
      ll t = s + A[j];
      if (t <= W and not seen[t]) {
        ans++;
        seen[t] = true;
      }
      REP2(k, j + 1, N) {
        ll v = t + A[k];
        if (v <= W and not seen[v]) {
          ans++;
          seen[v] = true;
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}

