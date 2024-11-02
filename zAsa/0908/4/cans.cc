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

  ll N, M; cin >> N >> M;
  // @InpVec(N, A) [kQr5Y4pt]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [kQr5Y4pt]

  map<ll, ll> mp;
  REP(i, 0, N) mp[A[i]]++;

  REP(i, 0, M) {
    ll b, c; cin >> b >> c;
    ll cnt = 0;
    for (auto it = mp.begin(); it != mp.end(); ) {
      auto [x, n] = *it;
      if (x >= c) break;
      if (cnt + n < b) {
        cnt += n;
        it = mp.erase(it);
      }else if (cnt + n == b) {
        cnt += n;
        it = mp.erase(it);
        break;
      }else {
        ll y = b - cnt;
        cnt += y;
        it->second -= y;
        break;
      }
    }
    mp[c] += cnt;
  }
  ll ans = 0;
  for (auto [x, c] : mp) {
    ans += x * c;
  }
  cout << ans << endl;

  return 0;
}

