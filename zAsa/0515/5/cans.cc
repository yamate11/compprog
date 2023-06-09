#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
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

  ll N, M; cin >> N >> M;
  if (N == 1) {
    if (M == 0) {
      cout << "1 2\n";
      return 0;
    }else {
      cout << -1 << endl;
      return 0;
    }
  }

  if (M < 0 or M > N - 2) {
    cout << -1 << endl;
    return 0;
  }
  ll lim = 1e6;
  cout << "1 " << lim << endl;
  REP(i, 0, M + 1) {
    cout << 2 + 2 * i << " " << 2 + 2 * i + 1 << "\n";
  }
  REP(i, M + 1, N - 1) {
    cout << lim + 2 * i << " " << lim + 2 * i + 1 << "\n";
  }

  return 0;
}

