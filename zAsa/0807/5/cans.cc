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

  auto func = [&](ll N, auto& A, ll val) {
    vector<pll> ret(N);
    ll p = -1;
    ll q = -1;
    REP(i, 0, N) {
      if (p < i) {
        p++;
        while (p < N and A[p] != val) p++;
      }
      if (q < i) {
        q++;
        while (q < N and A[q] <= val) q++;
      }
      ret[i] = pll(p, q);
    }
    return ret;
  };


  ll N; cin >> N;
  ll X, Y; cin >> X >> Y;
  // @InpVec(N, A) [hNlmuiF7]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [hNlmuiF7]

  auto v1 = func(N, A, X);
  REP(i, 0, N) A[i] = -A[i];
  auto v2 = func(N, A, -Y);
  ll ans = 0;
  REP(i, 0, N) {
    auto [a, b] = v1[i];
    auto [c, d] = v2[i];
    ll e = max(a, c);
    ll f = min(b, d);
    ll x = max(0LL, f - e);
    ans += x;
  }
  cout << ans << endl;

  return 0;
}

