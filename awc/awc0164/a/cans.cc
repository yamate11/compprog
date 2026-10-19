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
  // @InpMVec(N - 1, (U, V, W)) [p25agQgW]
  auto U = vector(N - 1, ll());
  auto V = vector(N - 1, ll());
  auto W = vector(N - 1, ll());
  for (int i = 0; i < N - 1; i++) {
    ll v1; cin >> v1; U[i] = v1;
    ll v2; cin >> v2; V[i] = v2;
    ll v3; cin >> v3; W[i] = v3;
  }
  // @End [p25agQgW]

  ll ans = accumulate(ALL(W), 0LL);
  cout << ans << "\n";

  return 0;
}

