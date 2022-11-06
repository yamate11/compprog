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
  // @InpVec(N, A) [5glqi3vE]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [5glqi3vE]
  /*
  vector<ll> B(N);
  */
  vector<ll> P2(N), P3(N);
  ll base = -1;
  ll vmin2 = 1e18;
  ll vmin3 = 1e18;
  REP(i, 0, N) {
    ll cnt2 = 0, cnt3 = 0;
    ll a = A[i];
    while (a % 2 == 0) {
      a /= 2;
      cnt2++;
    }
    while (a % 3 == 0) {
      a /= 3;
      cnt3++;
    }
    if (base < 0) {
      base = a;
    }else {
      if (base != a) {
        cout << -1 << endl;
        return 0;
      }
    }
    P2[i] = cnt2;
    P3[i] = cnt3;
    vmin2 = min(vmin2, cnt2);
    vmin3 = min(vmin3, cnt3);
  }
  ll ans = 0;
  REP(i, 0, N) {
    ans += P2[i] - vmin2;
    ans += P3[i] - vmin3;
  }
  cout << ans << endl;
  

  return 0;
}

