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

  ll N, X, Y; cin >> N >> X >> Y;
  // @InpVec(N, A) [1meCRgoD]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [1meCRgoD]
  string ans;
  if (X == Y) {
    ll cnt = 0;
    REP(i, 0, N) cnt += A[i] / X;
    if (cnt % 2 == 0) ans = "Second";
    else ans = "First";
  }else {
    ll ymin = min(X, Y);
    ll ymax = max(X, Y);
    ll xmid = 0, xlong = 0;
    REP(i, 0, N) {
      xlong += A[i] / (X + Y);
      ll rem = A[i] % (X + Y);
      if (ymin <= rem and rem < ymax) xmid++;
    }
    if (xmid == 0) ans = "Second";
    else {
      if (ymin == X) ans = "First";
      else ans = "Second";
    }
  }
  cout << ans << endl;


  return 0;
}

