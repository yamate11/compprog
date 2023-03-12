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

  ll N, K, X; cin >> N >> K >> X;
  priority_queue<ll> pque;
  REP(i, 0, N) {
    ll a; cin >> a;
    ll y = a / X;
    ll z = a % X;
    if (y <= K) {
      K -= y;
      if (z > 0) pque.push(z);
    }else {
      pque.push(a - K * X);
      K = 0;
    }
  }
  while (not pque.empty() and K > 0) {
    pque.pop();
    K--;
  }
  ll ans = 0;
  while (not pque.empty()) {
    ans += pque.top(); pque.pop();
  }
  cout << ans << endl;

  return 0;
}

