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
  // @InpVec(N, P) [9sRokNoc]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; P[i] = v; }
  // @End [9sRokNoc]

  if (N == 2) {
    ll ans = (P[0] == 1) ? 0 : 1;
    cout << ans << endl;
    return 0;
  }
  ll a = P[0], b = P[1];
  ll ans = -1;
  if (b == a + 1 or (a == N and b == 1)) {
    if (a == 1) ans = 0;
    else ans = min(N - a + 1, a - 1 + 2);
  }else {
    ans = min(a, N - a) + 1;
  }
  cout << ans << endl;

  return 0;
}

