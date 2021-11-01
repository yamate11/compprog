#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
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

  auto solve = [&]() -> void {
    ll N; cin >> N;
    string S; cin >> S;
    vector<ll> type2;
    REP(i, N) if (S[i] == '2') type2.push_back(i);
    ll cnt = SIZE(type2);
    if (1 <= cnt and cnt <= 2) {
      cout << "NO\n";
      return;
    }
    vector res(N, vector(N, 0LL));
    if (cnt >= 3) {
      REP(i, cnt - 1) {
        res[type2[i]][type2[i + 1]] = 1;
        res[type2[i + 1]][type2[i]] = -1;
      }
      res[type2[cnt-1]][type2[0]] = 1;
      res[type2[0]][type2[cnt-1]] = -1;
    }
    cout << "YES\n";
    REP(i, N) {
      REP(j, N) {
        if (i == j) cout << "X";
        else if (res[i][j] == 0) cout << "=";
        else if (res[i][j] == 1) cout << "+";
        else if (res[i][j] == -1) cout << "-";
      }
      cout << "\n";
    }
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

