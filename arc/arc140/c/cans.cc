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

  ll N, X; cin >> N >> X;
  ll p = X == N ? N - 1 : N;
  ll q = X == 1 ? 2 : 1;
  vector<ll> ans(N);
  ans[0] = X;
  {
    ll i = N - 1;
    while (true) {
      if (not (2 * X - 2 == N and i == N - 1)) {
        ans[i] = p;
        i--;
        p--;
        if (p == X) p--;
        if (i == 0) break;
      }
      ans[i] = q;
      i--;
      q++;
      if (q == X) q++;
      if (i == 0) break;
    }
  }
  REP(i, N) cout << ans[i] << " ";
  cout << endl;
  return 0;
}

