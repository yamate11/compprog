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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, A) [LUY0cHh7]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [LUY0cHh7]
  vector<ll> even, odd;
  REP(i, 0, N) {
    if (A[i] % 2 == 0) even.push_back(A[i]);
    else odd.push_back(A[i]);
  }
  sort(ALL(even), greater<ll>());
  sort(ALL(odd), greater<ll>());
  if (SIZE(even) == 1 and SIZE(odd) == 1) {
    cout << "-1\n";
  }else {
    ll ans = 0;
    if (SIZE(even) >= 2) ans = max(ans, even[0] + even[1]);
    if (SIZE(odd) >= 2) ans = max(ans, odd[0] + odd[1]);
    cout << ans << endl;
  }

  return 0;
}

