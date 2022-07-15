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

  ll N, Q; cin >> N >> Q;
  vector<bool> B(N + 1);
  REP(_q, Q) {
    ll l, r; cin >> l >> r; l--;
    B[l] = not B[l];
    B[r] = not B[r];
  }
  ll a = 0;
  REP(i, N) {
    if (B[i]) a = 1 - a;
    cout << a;
  }
  cout << endl;

  return 0;
}

