#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
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
  // @InpVec(N, A) [CoVsEE8w]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [CoVsEE8w]
  vector<ll> vec{0};
  ll x = 0;
  REP(i, 0, N) {
    x = (x + A[i]) % 360;
    vec.push_back(x);
  }
  vec.push_back(360);
  sort(ALL(vec));
  ll ans = 0;
  REP(i, 0, SIZE(vec) - 1) ans = max(ans, vec[i + 1] - vec[i]);
  cout << ans << endl;

  return 0;
}

