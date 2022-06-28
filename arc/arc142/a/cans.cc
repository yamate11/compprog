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

  auto solve = [&]() -> ll {
    ll N, K; cin >> N >> K;
    if (K % 10 == 0) return 0;
    string sk = to_string(K);
    reverse(ALL(sk));
    ll m = stoll(sk);
    if (K > m) return 0;
    ll ans = 0;
    for (ll x = m; x <= N; x *= 10) ans++;
    if (m != K) for (ll x = K; x <= N; x *= 10) ans++;
    return ans;
  };

  cout << solve() << endl;

  return 0;
}

