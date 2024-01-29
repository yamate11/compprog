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
  // @InpVec(M, X, dec=1) [YXgxhIi5]
  auto X = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; v -= 1; X[i] = v; }
  // @End [YXgxhIi5]
  vector<ll> vec(2 * N + 1);
  ll ans = 0;
  REP(i, 0, M - 1) {
    ll a = X[i];
    ll b = X[i + 1];
    if (a > b) swap(a, b);
    if ((b - a) * 2 != N) {
      if ((b - a) * 2 < N) {
        ans += b - a;
        ll diff = (N - (b - a)) - (b - a);
        vec[a] += diff;
        vec[b] -= diff;
      }else {
        ans += N - (b - a);
        ll diff = (b - a) - (N - (b - a));
        vec[b] += diff;
        vec[N + a] -= diff;
      }
    }else {
      ans += b - a;
    }
  }
  ll cur = 0;
  vector P(N, 0LL);
  REP(i, 0, 2*N) {
    cur += vec[i];
    if (i < N) P[i] += cur;
    else P[i - N] += cur;
  }
  ll mindiff = 1e18;
  REP(i, 0, N) mindiff = min(mindiff, P[i]);
  ans += mindiff;
  cout << ans << endl;

  return 0;
}

