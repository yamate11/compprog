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
    vector<ll> S;
    ll x, y;
    REP(i, 0, N) {
      if (i == 0) cin >> x;
      else if (i == N - 1) cin >> y;
      else {
        ll a; cin >> a;
        S.push_back(a);
      }
    }
    sort(ALL(S));
    ll cnt = 2;
    while (true) {
      if (y <= 2 * x) break;
      ll i = lower_bound(ALL(S), 2 * x + 1) - S.begin();
      i--;
      if (i < 0) return -1;
      if (S[i] <= x) return -1;
      x = S[i];
      cnt++;
    }
    return cnt;

  };
  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

