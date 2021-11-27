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
  ll minR = LLONG_MAX;
  ll maxL = LLONG_MIN;
  REP(i, N) {
    ll l, r; cin >> l >> r;
    minR = min(r, minR);
    maxL = max(l, maxL);
    if (maxL <= minR) {
      cout << 0 << "\n";
    }else {
      cout << (maxL - minR + 1) / 2 << "\n";
    }
  }

  return 0;
}

