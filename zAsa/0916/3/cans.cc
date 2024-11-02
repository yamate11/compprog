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
    ll cnt = 0;
    REP(i, 0, N) if (S[i] == '1') cnt++;
    if (cnt % 2 != 0) return -1;
    if (cnt != 2) return cnt / 2;
    ll a = -1, b = -1;
    REP(i, 0, N) {
      if (S[i] == '1') {
        if (a < 0) a = i;
        else b = i;
      }
    }
    if (b > a + 1) return 1;
    if (N == 3) return -1;
    if (N >= 5) return 2;
    if (S == "0110") return 3;
    return 2;
  };

  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

