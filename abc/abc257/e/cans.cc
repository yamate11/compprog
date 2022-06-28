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
  vector<ll> C(10);
  REP2(i, 1, 10) cin >> C[i];
  ll vmin = 1e10;
  // ll i0 = -1;
  REP2(i, 1, 10) if (C[i] < vmin) {
    vmin = C[i];
    // i0 = i;
  }
  ll nd = N / vmin;
  vector<ll> ans(nd);
  ll cost = 0;
  REP(i, nd) {
    bool found = false;
    REP2R(d, 9, 1) {
      if (cost + C[d] + vmin * (nd - (i + 1)) <= N) {
        cost += C[d];
        found = true;
        ans[i] = d;
        break;
      }
    }
    assert(found);
  }
  for (ll a : ans) cout << a;
  cout << endl;

  return 0;
}

