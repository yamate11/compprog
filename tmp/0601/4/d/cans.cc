#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  priority_queue<ll> pque;
  REP(i, N) {
    ll a; cin >> a;
    pque.push(a);
  }
  REP(i, M) {
    ll a = pque.top(); pque.pop();
    pque.push(a / 2);
  }
  ll ans = 0;
  while (not pque.empty()) {
    ll a = pque.top(); pque.pop();
    ans += a;
  }
  cout << ans << endl;

  return 0;
}

