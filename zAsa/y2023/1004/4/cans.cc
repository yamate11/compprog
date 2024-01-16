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
  priority_queue<ll> pque;
  REP(i, 0, N) {
    ll a; cin >> a;
    pque.push(a);
  }
  REP(i, 0, M) {
    ll x = pque.top(); pque.pop();
    pque.push(x / 2);
  }
  ll ans = 0;
  while (not pque.empty()) {
    ll x = pque.top(); pque.pop();
    ans += x;
  }
  cout << ans << endl;
  return 0;
}

