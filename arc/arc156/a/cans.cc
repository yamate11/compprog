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

  auto solve = [&]() -> ll {
    ll N; cin >> N;
    string S; cin >> S;
    vector<ll> pos;
    REP(i, 0, N) if (S[i] == '1') pos.push_back(i);
    ll cnt = SIZE(pos);
    if (cnt % 2 == 1) return -1;
    if (cnt == 0) return 0;
    if (cnt >= 4) return cnt / 2;
    assert(cnt == 2);
    if (pos[1] >= pos[0] + 2) return 1;
    if (N == 3) return -1;
    if (N >= 5) return 2;
    if (pos[0] == 1 and pos[1] == 2) return 3;
    return 2;
  };

  ll T; cin >> T;
  REP(_t, 0, T) cout << solve() << "\n";

  return 0;
}

