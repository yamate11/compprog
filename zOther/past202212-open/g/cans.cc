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

  ll N; cin >> N;
  // @InpVec(N, A) [UDjBfKxr]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [UDjBfKxr]

  vector<ll> S(N + 1, 0LL);
  REP(i, 0, N) S[i + 1] = S[i] + A[i];
  vector<ll> V(N + 1, 0LL);
  V[N] = S[N];
  REPrev(i, N - 1, 0) V[i] = max(S[i], V[i + 1]);
  ll ans = LLONG_MIN;
  REP(i, 0, N) {
    ll x = V[i + 1] - S[i];
    ans = max(ans, x);
  }
  cout << ans << endl;

  return 0;
}

