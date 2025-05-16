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
  // @InpMVec(N, (X, Y, T, R)) [hT98QUlf]
  auto X = vector(N, ll());
  auto Y = vector(N, ll());
  auto T = vector(N, ll());
  auto R = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; X[i] = v1;
    ll v2; cin >> v2; Y[i] = v2;
    ll v3; cin >> v3; T[i] = v3;
    ll v4; cin >> v4; R[i] = v4;
  }
  // @End [hT98QUlf]

  double big = 1e18;
  vector dist(N, big);
  using sta = pair<double, ll>;
  priority_queue<sta, vector<sta>, greater<sta>> pque;
  dist[0] = 0.0;
  pque.emplace(0.0, 0);
  while (not pque.empty()) {
    auto [d, nd] = pque.top(); pque.pop();
    if (dist[nd] == d) {
      REP(i, 0, N) {
        if (i == nd) continue;
        double v = min(T[nd], R[i]);
        double dx = X[i] - X[nd];
        double dy = Y[i] - Y[nd];
        double s = sqrt(dx * dx + dy * dy);
        double len = s / v;
        double new_dist = d + len;
        if (new_dist < dist[i]) {
          dist[i] = new_dist;
          pque.emplace(new_dist, i);
        }
      }
    }
  }
  sort(ALL(dist), greater<double>());
  REP(i, 0, N - 1) dist[i] += i;
  double ans = *max_element(ALL(dist));
  cout << ans << endl;

  return 0;
}

