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

  ll N, K; cin >> N >> K;
  // @InpVec(N, S, type=string) [9UCzm8BT]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [9UCzm8BT]
  ll ans = 0;
  REP(x, 0, 1LL << N) {
    vector cnt(26, 0LL);
    REP(t, 0, N) {
      if (x >> t & 1) {
        for (char c : S[t]) {
          cnt[c - 'a']++;
        }
      }
    }
    ll a = 0;
    REP(i, 0, 26) if (cnt[i] == K) a++;
    ans = max(ans, a);
  }
  cout << ans << endl;
  return 0;
}

