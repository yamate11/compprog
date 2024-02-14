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
  // @InpMVec(N - 1, (A, B, (X, dec=1))) [ZckMruQ1]
  auto A = vector(N - 1, ll());
  auto B = vector(N - 1, ll());
  auto X = vector(N - 1, ll());
  for (int i = 0; i < N - 1; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
    ll v3; cin >> v3; v3 -= 1; X[i] = v3;
  }
  // @End [ZckMruQ1]

  priority_queue<pll, vector<pll>, greater<pll>> pque;
  ll big = 1e18;
  vector dist(N, big);
  dist[0] = 0;
  pque.emplace(0, 0);
  while (not pque.empty()) {
    auto [d, nd] = pque.top(); pque.pop();
    if (dist[nd] == d) {
      if (nd == N - 1) {
        cout << d << endl;
        return 0;
      }
      ll new_d1 = d + A[nd];
      ll peer_1 = nd + 1;
      if (new_d1 < dist[peer_1]) {
        dist[peer_1] = new_d1;
        pque.emplace(new_d1, peer_1);
      }
      ll new_d2 = d + B[nd];
      ll peer_2 = X[nd];
      if (new_d2 < dist[peer_2]) {
        dist[peer_2] = new_d2;
        pque.emplace(new_d2, peer_2);
      }
    }
  }
  assert(0);

  return 0;
}

