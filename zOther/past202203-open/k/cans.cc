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

  ll big = 1e18;
  ll N, M; cin >> N >> M;

  auto f = [&](ll start, const auto& A, const auto& B, const auto& W) -> vector<ll> {
    vector nbr(N, vector<pll>());
    REP(i, 0, ssize(A)) nbr[A[i]].emplace_back(B[i], W[i]);

    vector dist(N, big);
    priority_queue<pll, vector<pll>, greater<pll>> pque;
    dist[start] = 0;
    pque.emplace(0, start);
    while (not pque.empty()) {
      auto [len, nd] = pque.top(); pque.pop();
      if (len == dist[nd]) {
        for (auto [peer, w] : nbr[nd]) {
          ll new_d = len + w;
          if (new_d < dist[peer]) {
            dist[peer] = new_d;
            pque.emplace(new_d, peer);
          }
        }
      }
    }
    return dist;
  };

  // @InpMVec(M, ((U, dec=1), (V, dec=1), W)) [HS8Hnki5]
  auto U = vector(M, ll());
  auto V = vector(M, ll());
  auto W = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; U[i] = v1;
    ll v2; cin >> v2; v2 -= 1; V[i] = v2;
    ll v3; cin >> v3; W[i] = v3;
  }
  // @End [HS8Hnki5]
  auto distA = f(0, U, V, W);
  auto distB = f(N - 1, V, U, W);
  REP(k, 0, N) {
    ll a = distA[k] + distB[k];
    if (a >= big) a = -1;
    cout << a << endl;
  }

  return 0;
}

