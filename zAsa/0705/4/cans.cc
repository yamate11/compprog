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

  ll K, T; cin >> K >> T;
  // @InpVec(T, A) [1Injq3E1]
  auto A = vector(T, ll());
  for (int i = 0; i < T; i++) { ll v; cin >> v; A[i] = v; }
  // @End [1Injq3E1]
  ll a = *ranges::max_element(A);
  ll b = K - a;
  ll ans;
  if (a <= b + 1) ans = 0;
  else ans = a - (b + 1);
  cout << ans << endl;

  return 0;
}

