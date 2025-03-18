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

  ll N; cin >> N;
  // @InpVec(N, P, dec=1) [JOeTWmFB]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; P[i] = v; }
  // @End [JOeTWmFB]

  vector revP(N, 0LL);
  REP(i, 0, N) revP[P[i]] = i;
  set<ll> ss;
  ss.insert(-1);
  ss.insert(N);
  ss.insert(revP[N - 1]);
  ll ans = 0;
  REPrev(i, N - 2, 0) {
    ll a = revP[i];
    auto it1 = ss.lower_bound(a);
    ll b = *it1;
    ll c = (b < N) ? *next(it1) : N;
    it1--;
    ll d = *it1;
    ll e = (d > -1) ? *prev(it1) : -1;
    ll ta = 0;
    if (b < N) ta += (a - d) * (c - b);
    if (d > -1) ta += (b - a) * (d - e);
    ans += ta * (i + 1);
    ss.insert(a);
  }
  cout << ans << endl;

  return 0;
}

