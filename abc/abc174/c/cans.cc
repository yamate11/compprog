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

  auto solve = [&]() -> ll {
    ll K; cin >> K;
    vector<bool> visited(K);
    for (ll i = 1, t = 7 % K; true; i++, t = (t * 10 + 7) % K) {
      if (t == 0) return i;
      if (visited[t]) return -1;
      visited[t] = true;
    }
  };
  cout << solve() << endl;
  return 0;
}

