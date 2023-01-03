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
  // @InpVec(N, A) [yvIzz6Ky]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [yvIzz6Ky]
  auto f = [&](bool b) -> ll {
    ll ret = 0;
    ll s = 0;
    REP(i, 0, N) {
      s += A[i];
      if (b and s <= 0) {
        ret += 1 - s;
        s = 1;
      }else if (not b and s >= 0) {
        ret += s + 1;
        s = -1;
      }
      b = not b;
    }
    return ret;
  };
  ll x = f(true);
  ll y = f(false);
  cout << min(x, y) << endl;

  return 0;
}

