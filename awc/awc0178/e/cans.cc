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

  ll N, M, K; cin >> N >> M >> K;
  vector B(M, 0LL);
  vector C(M, 0LL);
  REP(i, 0, M) {
    REP(j, 0, N) {
      ll b; cin >> b;
      if (b == 1) B[i] |= (1LL << j);
    }
    cin >> C[i];
  }
  vector<bool> danger(1LL << N, false);
  REP(i, 0, K) {
    ll pat = 0;
    REP(j, 0, N) {
      ll f; cin >> f;
      if (f == 1) pat |= (1LL << j);
    }
    danger[pat] = true;
  }
  
  ll big = 1LL << 60;
  vector<ll> dist(1LL << N, big);
  priority_queue<pll, vector<pll>, greater<pll>> pque;
  dist[0] = 0;
  pque.emplace(0, 0);
  while (not pque.empty()) {
    auto [d, nd] = pque.top(); pque.pop();
    if (dist[nd] == d) {
      REP(i, 0, M) {
        ll peer = nd ^ B[i];
        ll new_d = d + C[i];
        if (not danger[peer] and dist[peer] > new_d) {
          dist[peer] = new_d;
          pque.emplace(new_d, peer);
        }
      }
    }
  }
  ll goal = (1LL << N) - 1;
  ll ans = dist[goal];
  if (ans == big) ans = -1;
  cout << ans << "\n";

  return 0;
}

