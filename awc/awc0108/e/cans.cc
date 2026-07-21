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

  ll N, K, T; cin >> N >> K >> T; T--;
  // @InpVec(N, S) [2lxQyVP3]
  auto S = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; S[i] = v; }
  // @End [2lxQyVP3]
  S[T] = 0;
  ll lo = max(0LL, T + 1 - K);
  ll hi = min(T, N - K);
  multiset<ll> ms;
  REP(i, 0, K) ms.insert(S[lo + i]);
  ll x0 = *ms.begin();
  ll ans = x0;
  REP(i, lo + 1, hi + 1) {
    auto it = ms.find(S[i - 1]);
    ms.erase(it);
    ms.insert(S[i + K - 1]);
    ll x = *ms.begin();
    ans = max(ans, x);
  }
  cout << ans << endl;
  return 0;
}

