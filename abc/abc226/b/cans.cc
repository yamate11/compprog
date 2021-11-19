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
  vector<vector<ll>> vec(N);
  REP(i, N) {
    ll L; cin >> L;
    REP(j, L) {
      ll a; cin >> a;
      vec[i].push_back(a);
    }
  }
  sort(ALL(vec));
  vec.erase(unique(ALL(vec)), vec.end());
  cout << SIZE(vec) << endl;

  return 0;
}

