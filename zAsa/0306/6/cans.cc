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

  ll N, x; cin >> N >> x;
  if (2 <= x and x <= 2*N - 2) {
    cout << "Yes\n";
    vector<ll> ans(2 * N - 1);
    ll p = N - x;
    if (p < 0) p += 2*N - 1;
    REP(i, 1, 2*N) {
      ans[p] = i;
      p++;
      if (p >= 2*N - 1) p = 0;
    }
    REPOUT(i, 0, 2*N - 1, ans[i], "\n");
  }else {
    cout << "No\n";
  }

  return 0;
}

