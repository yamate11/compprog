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

  ll N, T; cin >> N >> T;
  // @InpVec(N, A) [Kr1686Ff]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [Kr1686Ff]
  if (N == 1) {
    cout << A[0] << endl;
    return 0;
  }
  ll H = N / 2;
  set<ll> ss;
  ss.insert(0);
  auto f = [&](ll z) -> ll {
    auto it = ss.lower_bound(z);
    if (it == ss.end()) return *prev(it);
    else if (*it == z) return z;
    else return *prev(it);
  };

  REP(x, 0, 1LL << H) {
    ll a = 0;
    REP(i, 0, H) if (x >> i & 1) a += A[i];
    if (a <= T) ss.insert(a);
  }
  ll HH = N - H;
  ll ans = f(T);
  REP(y, 0, 1LL << HH) {
    ll b = 0;
    REP(i, 0, HH) if (y >> i & 1) b += A[H + i];
    if (b <= T) ans = max(ans, b + f(T - b));
  }
  cout << ans << endl;

  return 0;
}

