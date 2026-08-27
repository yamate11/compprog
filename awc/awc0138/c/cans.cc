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
  // @InpMVec(N, (A, B)) [W1NdSNZA]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
  }
  // @End [W1NdSNZA]

  vector<ll> CA(N + 1), CB(N + 1);
  REP(i, 0, N) {
    CA[i + 1] = CA[i] + A[i];
    CB[i + 1] = CB[i] + B[i];
  }
  ll j = 0;
  ll ans = 0;
  REP(i, 0, N) {
    for (; j < N + 1 and CB[j] - CB[i] <= K; j++);
    ans = max(ans, CA[j - 1] - CA[i]);
  }
  cout << ans << "\n";

  return 0;
}

