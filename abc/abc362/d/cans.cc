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

  ll N, M; cin >> N >> M;
  // @InpVec(N, A) [GYKKUxyh]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [GYKKUxyh]
  // @InpMVec(M, ((U, dec=1), (V, dec=1), B)) [o3iUL3KS]
  auto U = vector(M, ll());
  auto V = vector(M, ll());
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; U[i] = v1;
    ll v2; cin >> v2; v2 -= 1; V[i] = v2;
    ll v3; cin >> v3; B[i] = v3;
  }
  // @End [o3iUL3KS]

  vector nbr(N, vector<pll>());
  REP(i, 0, M) {
    nbr[U[i]].emplace_back(V[i], B[i]);
    nbr[V[i]].emplace_back(U[i], B[i]);
  }
  auto id_in = [&](ll i) -> ll { return 2 * i + 0; };
  auto id_out = [&](ll i) -> ll {return 2 * i + 1; };
  ll big = 1e18;
  vector dist(2*N, big);
  priority_queue<pll, vector<pll>, greater<pll>> pque;
  dist[id_in(0)] = 0;
  pque.emplace(0, id_in(0));
  while (not pque.empty()) {
    auto [d, e] = pque.top(); pque.pop();
    if (dist[e] == d) {
      ll i = e / 2;
      ll rem = e % 2;
      if (rem == 0) {
        ll peer = id_out(i);
        ll new_d = d + A[i];
        if (new_d < dist[peer]) {
          dist[peer] = new_d;
          pque.emplace(new_d, peer);
        }
      }else {
        for (auto [j, len] : nbr[i]) {
          ll peer = id_in(j);
          ll new_d = d + len;
          if (new_d < dist[peer]) {
            dist[peer] = new_d;
            pque.emplace(new_d, peer);
          }
        }
      }
    }
  }
  REP(i, 1, N) {
    cout << dist[id_out(i)] << " ";
  }
  cout << endl;

    


  return 0;
}

