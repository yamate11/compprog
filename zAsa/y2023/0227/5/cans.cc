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

  ll N; cin >> N;
  REP(k, 0, N + 10) {
    ll p = k * (k - 1) / 2;
    if (p > N) {
      cout << "No\n";
      return 0;
    }
    if (p == N) {
      cout << "Yes\n";
      vector ans(k, vector<ll>());
      ll t = 0;
      REP(x, 0, k) REP(y, x + 1, k) {
        ans[x].push_back(t);
        ans[y].push_back(t);
        t++;
      }
      cout << k << endl;
      REP(i, 0, k) {
        cout << SIZE(ans[i]) << " ";
        REPOUT(j, 0, SIZE(ans[i]), ans[i][j] + 1, " ");
      }
      return 0;
    }
  }
  assert(0);

  return 0;
}

