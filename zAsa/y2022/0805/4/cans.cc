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

  ll N, M; cin >> N >> M;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  vector fwd(N, vector<ll>());
  vector numBwd(N, 0LL);
  REP(i, M) {
    ll x, y; cin >> x >> y; x--; y--;
    fwd[x].push_back(y);
    numBwd[y] ++;
  }
  ll ans = LLONG_MIN;
  vector<ll> tops;
  vector<ll> vmin(N, LLONG_MAX);
  REP(i, N) {
    if (numBwd[i] == 0) tops.push_back(i);
  }
  while (not tops.empty()) {
    ll x = tops.back(); tops.pop_back();
    ans = max(ans, A[x] - vmin[x]);
    for (ll z : fwd[x]) {
      vmin[z] = min(vmin[z], min(A[x], vmin[x]));
      numBwd[z]--;
      if (numBwd[z] == 0) tops.push_back(z);
    }
  }
  cout << ans << endl;

  return 0;
}

