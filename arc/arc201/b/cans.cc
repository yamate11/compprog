#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> ll {
    ll limX = 60;

    ll N, W; cin >> N >> W;
    vector vec(limX, vector<ll>());
    REP(i, 0, N) {
      ll x, y; cin >> x >> y;
      vec[x].push_back(y);
    }
    REP(x, 0, limX) sort(ALL(vec[x]), greater<ll>());
    ll x = 0;
    ll ans = 0;
    while (W > 0) {
      ll i0 = 0;
      if (W % 2 != 0) {
        if (ssize(vec[x]) > 0) {
          ans += vec[x][0];
          i0 = 1;
        }
      }
      W /= 2;
      if (W == 0) break;
      if (x == limX - 1) break;
      vector<ll> mg;
      ll sz0 = ssize(vec[x]);
      ll sz1 = ssize(vec[x + 1]);
      ll i = i0;
      ll j = 0;
      while (i < sz0 or j < sz1) {
        ll a, b;
        if (i >= sz0)          a = -1;
        else if (i + 1 == sz0) a = vec[x][i];
        else                   a = vec[x][i] + vec[x][i + 1];
        if (j >= sz1)          b = -1;
        else                   b = vec[x + 1][j];
        if (a > b) {
          mg.push_back(a);
          i += 2;
        }else {
          mg.push_back(b);
          j += 1;
        }
      }
      vec[x + 1] = move(mg);
      x++;
    }
    return ans;
  };

  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

