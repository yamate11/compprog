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

  auto solve = [&]() -> string {
    ll N; cin >> N;
    string s1, s2, s3; cin >> s1 >> s2 >> s3;
    string ans(2*N + 1, '0');
    REP2(i, N, 2*N) ans[i] = '1';
    return ans;
  };
  

  ll T; cin >> T;
  REP(i, T) cout << solve() << "\n";

  return 0;
}

