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
  string S; cin >> S;
  vector vec(4, vector(1000, false));
  for (char c : S) {
    ll d = c - '0';
    REP2(i, 0, 100) if (vec[2][i]) vec[3][10 * i + d] = true;
    REP2(i, 0, 10) if (vec[1][i]) vec[2][10 * i + d] = true;
    vec[1][d] = true;
  }
  ll cnt = 0;
  REP(i, 1000) if (vec[3][i]) cnt++;
  cout << cnt << endl;

  return 0;
}

