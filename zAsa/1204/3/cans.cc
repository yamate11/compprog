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
  // @InpVec(N, L) [9sz6LHGX]
  auto L = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; L[i] = v; }
  // @End [9sz6LHGX]
  ranges::sort(L);

  ll ans = 0;
  REP(i, 0, N) REP(j, i + 1, N) {
    ll k = ranges::lower_bound(L, L[i] + L[j]) - L.begin();
    ans += k - (j + 1);
  }
  cout << ans << endl;
  return 0;
}

