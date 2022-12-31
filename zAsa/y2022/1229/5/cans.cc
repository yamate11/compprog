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
  // @InpVec(N, A) [tvRCL7qr]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [tvRCL7qr]
  ll s = 0;
  REP(i, 0, N) s += i * A[i];
  REP(i, 0, N - 1) s += i;
  ll ans = s;
  vector<ll> S(N + 1);
  REP(i, 0, N) S[i + 1] = S[i] + A[i];
  ll xl = 0, xr = N - 2;
  for (ll j = 1; j < N; j+= 2) {
    s += 2 * (S[j] +  - (S[N] - S[j + 1])) + xl + (xl + 1) - (xr + xr - 1);
    xl += 2;
    xr -= 2;
    ans = min(ans, s);
  }
  cout << ans << endl;

  return 0;
}

