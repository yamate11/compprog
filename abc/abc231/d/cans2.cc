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
  vector<vector<ll>> nbr(N);
  REP(i, M) {
    ll a, b; cin >> a >> b; a--; b--;
    nbr[a].push_back(b);
    nbr[b].push_back(a);
    if (SIZE(nbr[a]) >= 3) {
      cout << "No" << endl;
      return 0;
    }
    if (SIZE(nbr[b]) >= 3) {
      cout << "No" << endl;
      return 0;
    }
  }
  REP(i, N) {
    if (SIZE(nbr[i]) == 1) {
      ll j = nbr[i][0];
      nbr[i].resize(0);
      ll prev = i;
      while (SIZE(nbr[j]) == 2) {
        if (nbr[j][0] == prev) swap(nbr[j][0], nbr[j][1]);
        ll j0 = nbr[j][0];
        nbr[j].resize(0);
        prev = j;
        j = j0;
        
      }
      nbr[j].resize(0);
    }
  }
  REP(i, N) {
    if (SIZE(nbr[i]) > 0) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

  return 0;
}

