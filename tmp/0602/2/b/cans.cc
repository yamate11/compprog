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
  vector<bool> rec(W + 1);
  REP(i, N) {
    ll a = A[i];
    if (a > W) continue;
    rec[a] = true;
    REP2(j, i + 1, N) {
      ll b = a + A[j];
      if (b > W) continue;
      rec[b] = true;
      REP2(k, j + 1, N) {
        ll c = b + A[k];
        if (c > W) continue;
        rec[c] = true;
      }
    }
  }
  ll cnt = 0;
  REP(i, W + 1) if (rec[i]) cnt++;
  cout << cnt << endl;

  return 0;
}

