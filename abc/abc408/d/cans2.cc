#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
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

  auto solve = [&]() -> ll {
    ll N; cin >> N;
    string S; cin >> S;
    ll tot = 0;
    REP(i, 0, N) if (S[i] == '1') tot++;
    vector<ll> v(N + 1);
    REP(i, 0, N) v[i + 1] = v[i] + (S[i] == '0' ? -1 : 1);
    ll ans = 1e18;
    ll amin = 0;
    REP(i, 0, N + 1) {
      ans = min(ans, amin - v[i]);
      amin = min(amin, v[i]);
    }
    return ans + tot;
  };

  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

