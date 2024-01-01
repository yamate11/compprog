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

  ll K, G, M; cin >> K >> G >> M;
  ll g = 0, m = 0;
  REP(i, 0, K) {
    if (g == G) g = 0;
    else if (m == 0) m = M;
    else {
      ll x = 0;
      if (g + m <= G) x = m;
      else x = G - g;
      m -= x;
      g += x;
    }
  }
  cout << g << " " << m << endl;

  return 0;
}

