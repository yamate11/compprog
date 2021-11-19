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
  vector<ll> X(N), Y(N);
  REP(i, N) cin >> X[i] >> Y[i];
  using sta = pair<ll, ll>;
  vector<sta> P;
  REP(i, N) REP2(j, i + 1, N) {
    ll x = X[j] - X[i];
    ll y = Y[j] - Y[i];
    if (y < 0) { x = -x; y = -y; } 
    if (y == 0) { x = 1; }
    P.emplace_back(x, y);
  }
  sort(ALL(P),
       [&](sta& p, sta& q) -> bool {
         auto [x0, y0] = p;
         auto [x1, y1] = q;
         return x0 * y1 > x1 * y0;
       });

  auto para = [&](const sta& p, const sta& q) -> bool {
    auto [x0, y0] = p;
    auto [x1, y1] = q;
    return x0 * y1 == x1 * y0;
  };

  ll cnt = 0;
  REP(i, SIZE(P)) {
    if (i == 0 or not para(P[i-1], P[i])) cnt++;
  }
  cout << cnt * 2 << endl;


  return 0;
}

