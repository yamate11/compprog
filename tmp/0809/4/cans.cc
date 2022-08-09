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
  vector<ll> numB(N, 1LL);
  vector<bool> red(N, false);
  red[0] = true;
  REP(i, M) {
    ll x, y; cin >> x >> y; x--; y--;
    assert(numB[x] > 0);
    if (red[x]) red[y] = true;
    numB[x]--;
    numB[y]++;
    if (numB[x] == 0) red[x] = false;
  }
  ll cnt = 0;
  REP(i, N) if (red[i]) cnt++;
  cout << cnt << endl;

  return 0;
}

