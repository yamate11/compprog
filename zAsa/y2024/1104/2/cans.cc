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

  ll N, K; cin >> N >> K;
  // @InpVec(N, C) [TIaa61nN]
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
  // @End [TIaa61nN]

  map<ll, ll> mp;
  ll cnt = 0;
  ll ans = 0;
  REP(i, 0, K) {
    if (mp[C[i]] == 0) cnt++;
    mp[C[i]]++;
    ans = max(ans, cnt);
  }
  REP(i, K, N) {
    ll x = --mp[C[i - K]];
    if (x == 0) cnt--;
    if (mp[C[i]] == 0) cnt++;
    mp[C[i]]++;
    ans = max(ans, cnt);
  }
  cout << ans << endl;



  return 0;
}

