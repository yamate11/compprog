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

  vector<ll> cnt(14);
  REP(i, 5) {
    ll a; cin >> a;
    cnt[a]++;
  }
  bool two = false, three = false;
  REP2(i, 1, 14) {
    if (cnt[i] == 2) two = true;
    if (cnt[i] == 3) three = true;
  }
  cout << ((two and three) ? "Yes" : "No") << endl;

  return 0;
}

