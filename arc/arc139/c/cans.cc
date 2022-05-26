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
  vector<ll> rec(8, -1);
  vector<pair<ll, ll>> ans;
  REP2(a, 4, N + 3 * M + 1) {
    ll m = 3 * a % 8;
    ll b = (rec[m] < 0) ? m : rec[m] + 8;
    while (not (a + 8 <= 3*b and 3*a - 8*M <= b)) b += 8;
    if (not (3*b <= a + 8*N and b <= 3*a - 8)) continue;
    rec[m] = b;
    ans.emplace_back((3*b - a) / 8, (3*a - b) / 8);
  }
  cout << SIZE(ans) << "\n";
  for (auto [x, y] : ans) cout << x << " " << y << "\n";

  return 0;
}

