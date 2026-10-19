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

  ll N, K, M; cin >> N >> K >> M;
  // @InpMVec(K, (B, D)) [YSz47qvw]
  auto B = vector(K, ll());
  auto D = vector(K, ll());
  for (int i = 0; i < K; i++) {
    ll v1; cin >> v1; B[i] = v1;
    ll v2; cin >> v2; D[i] = v2;
  }
  // @End [YSz47qvw]

  ranges::sort(D, greater<ll>());
  ll ans = 0;
  for (ll i = 0; i < K; i += M) {
    ans += D[i] * 2;
  }
  cout << ans << "\n";

  return 0;
}

