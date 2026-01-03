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
  // @InpVec(N, A) [01JBJSWS]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [01JBJSWS]

  auto f = [&](bool b) -> ll {
    ll ans = 0;
    ll cum = 0;
    REP(i, 0, N) {
      cum += A[i];
      if (b) {
        if (cum <= 0) {
          ans += 1 - cum;
          cum = 1;
        }
      }else {
        if (cum >= 0) {
          ans += cum - (-1);
          cum = -1;
        }
      }
      b = not b;
    }
    return ans;
  };

  ll x = f(true);
  ll y = f(false);
  cout << min(x, y) << endl;

  return 0;
}

