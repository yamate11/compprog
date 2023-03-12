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

  ll N, M; cin >> N >> M;
  // @InpVec(N, A, dec=1) [JVP8SvJX]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [JVP8SvJX]

  vector revA(M, vector<ll>());
  REP(i, 0, N) revA[A[i]].push_back(i);
  ll val = 0;
  ll nUse = 0, nDir = 0;
  REP(i, 0, N - 1) {
    if (A[i] < A[i + 1]) {
      val += A[i + 1] - A[i];
      nDir++;
    }else {
      val += 1 + A[i + 1];
      nUse++;
    }
  }
  ll ans = val;
  REP(p, 0, M) {
    ll a = 0, b = 0;
    for (ll i : revA[p]) {
      if (i > 0) {
        ll d = A[i] - A[i - 1];
        if (d < 0) d += M;
        val += d - 1;
        a++;
      }
      if (i < N - 1) {
        b++;
      }
    }
    val -= nUse - a;
    nUse = nUse - a + b;
    nDir = nDir + a - b;
    ans = min(ans, val);
  }
  cout << ans << endl;
  return 0;
}

