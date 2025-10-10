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

  ll M; cin >> M;
  // @InpMVec(M, (D, C)) [UKUcnPVK]
  auto D = vector(M, ll());
  auto C = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; D[i] = v1;
    ll v2; cin >> v2; C[i] = v2;
  }
  // @End [UKUcnPVK]
  ll k = accumulate(ALL(C), 0LL);
  ll v = 0;
  REP(i, 0, M) v += D[i] * C[i];
  ll ans = k - 1 + ((v - 1) / 9);
  cout << ans << endl;

  return 0;
}

