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
  // @InpMVec(N, (P, (C, dec=1))) [58nz53St]
  auto P = vector(N, ll());
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; P[i] = v1;
    ll v2; cin >> v2; v2 -= 1; C[i] = v2;
  }
  // @End [58nz53St]
  // @InpMVec(M, ((U, dec=1), (V, dec=1), (K, dec=1))) [dVbeXRra]
  auto U = vector(M, ll());
  auto V = vector(M, ll());
  auto K = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; U[i] = v1;
    ll v2; cin >> v2; v2 -= 1; V[i] = v2;
    ll v3; cin >> v3; v3 -= 1; K[i] = v3;
  }
  // @End [dVbeXRra]

  vector fwd(N, vector<pll>());
  vector pathPerKey(N, vector<ll>());
  REP(i, 0, M) {
    fwd[U[i]].emplace_back(V[i], K[i]);
    pathPerKey[K[i]].push_back(i);
  }

  vector<bool> seen(N);
  vector<bool> visited(N);
  queue<ll> visiting;
  vector<bool> hasKey(N);
  seen[0] = true;
  visiting.push(0);
  while (not visiting.empty()) {
    ll nd = visiting.front(); visiting.pop();
    if (P[nd]) {
      ll k0 = C[nd];
      if (not hasKey[k0]) {
        hasKey[k0] = true;
        for (ll i : pathPerKey[k0]) {
          if (visited[U[i]] and not seen[V[i]]) {
            seen[V[i]] = true;
            visiting.push(V[i]);
          }
        }
      }
    }
    for (auto [peer, k] : fwd[nd]) {
      if (hasKey[k] and not seen[peer]) {
        seen[peer] = true;
        visiting.push(peer);
      }
    }
    visited[nd] = true;
  }
  cout << (visited[N - 1] ? "Yes" : "No") << endl;
  return 0;
}

