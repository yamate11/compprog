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

  ll N, X, Y; cin >> N >> X >> Y;
  // @InpVec(N, A) [YWhj4HG9]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [YWhj4HG9]

  auto func = [&](ll a, ll b) -> ll {
    ll i = 0;
    ll j = 0;
    ll out = 0;
    ll ret = 0;
    while (true) {
      if (out == 0) {
        ret += j - i;
        if (j == N) break;
        if (A[j] < a or b < A[j]) out++;
        j++;
      }else {
        if (A[i] < a or b < A[i]) out--;
        i++;
      }
    }
    return ret;
  };
  ll ans = func(Y, X) - func(Y + 1, X) - func(Y, X - 1) + func(Y + 1, X - 1);
  cout << ans << endl;

  return 0;
}

