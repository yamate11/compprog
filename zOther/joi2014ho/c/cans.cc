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
  // @InpVec(N, A) [h0PlngJH]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [h0PlngJH]
  A.resize(2 * N);
  REP(i, 0, N) A[N + i] = A[i];
  vector<ll> S(2 * N + 1);
  REP(i, 0, 2 * N) S[i + 1] = S[i] + A[i];
  ll ans = 0;
  ll p = 0, q = 0, r = 0;
  while (p < N) {
    ll base = S[q] - S[p];
    while (r + 1 <= p + N and S[r + 1] - S[q] < S[p + N] - S[r + 1]) r++;
    ll a1 = S[r] - S[q];
    ll b1 = S[p + N] - S[r];
    ll a2 = S[r + 1] - S[q];
    ll b2 = S[p + N] - S[r + 1];
    ll x = max(min(a1, b1), min(a2, b2));
    ll y = min(base, x);
    ans = max(ans, y);
    if (base < x) q++;
    else p++;
  }
  cout << ans << endl;

  return 0;
}

