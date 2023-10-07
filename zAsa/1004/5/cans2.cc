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
  // @InpVec(N, A) [TLoyWa3y]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [TLoyWa3y]

  auto func = [&]() -> vector<ll> {
    auto S = vector(N + 1, 0LL);
    REP(i, 0, N) S[i + 1] = S[i] + A[i];
    ll sz = (N + 1) / 2;
    auto ret = vector(sz, 0LL);
    ll z = 0;
    REP(i, 1, N) z += i * A[i];
    REP(i, 1, N - 1) z += i;
    ret[0] = z;
    REP(i, 0, sz - 2) {
      ll d1 = A[1 + 2*i] + 2 * A[2 + 2*i] + 2 + 1;
      ll d2 = 2 * (S[N] - S[2 * i + 3]);
      ll d3 = 2 * (N - (2 * i + 4));
      ll d = d1 + d2 + d3;
      ret[i + 1] = ret[i] - d;
    }
    ret[sz - 1] = 0;
    return ret;
  };

  auto vec1 = func();
  reverse(ALL(A));
  auto vec2 = func();
  reverse(ALL(vec2));
  ll ans = 1e18;
  REP(i, 0, SIZE(vec1)) ans = min(ans, vec1[i] + vec2[i]);
  cout << ans << endl;
  

  return 0;
}

