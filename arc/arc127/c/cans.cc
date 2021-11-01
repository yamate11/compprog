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
  string X; cin >> X;
  reverse(ALL(X));
  vector<ll> Y(N);
  REP(i, SIZE(X)) Y[i] = X[i] - '0';
  string ans = "1";
  auto subt = [&](ll lim) -> bool {
    REP(j, lim) {
      if (Y[j] == 1) {
        Y[j] = 0;
        return true;
      }
      Y[j] = 1;
    }
    return false;
  };
  subt(N);
  REP2R(i, N - 1, 1) {
    if (Y[i] == 1) {
      Y[i] = 0;
      ans += '1';
    }else {
      if (subt(i)) {
        ans += '0';
      }else {
        break;
      }
    }
  }
  cout << ans << endl;

  return 0;
}

