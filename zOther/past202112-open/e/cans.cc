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

  string N; cin >> N;
  vector<ll> hand{1, 0, 0, 0, 0, 0, 1, 1, 1, 1};
  ll ans = 500;
  REP(i, 1, SIZE(N)) {
    if (N[i - 1] == N[i]) ans += 301;
    else if (hand[N[i - 1] - '0'] == hand[N[i] - '0']) ans += 210;
    else ans += 100;
  }
  cout << ans << endl;
  return 0;
}

