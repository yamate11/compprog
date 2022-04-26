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

  ll N, K; cin >> N >> K;
  vector<string> S(N);
  REP(i, N) cin >> S[i];
  ll ans = 0;
  REP(x, 1LL << N) {
    vector<ll> cnt(26);
    REP(i, N) {
      if (x >> i & 1) {
        for (auto c : S[i]) {
          cnt[c - 'a'] ++;
        }
      }
    }
    ll k = 0;
    REP(i, 26) {
      if (cnt[i] == K) k++;
    }
    ans = max(ans, k);
  }
  cout << ans << endl;

  return 0;
}

