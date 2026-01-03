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
  // @InpVec(N, A) [8KoKCqN9]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [8KoKCqN9]
  // @InpVec(N, S, type=string) [V9jfijAw]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [V9jfijAw]

  ll big = 1e10;
  vector dist(N, vector(N, pll(big, 0)));
  REP(i, 0, N) dist[i][i] = pll(0, 0);
  REP(i, 0, N) REP(j, 0, N) {
    if (S[i][j] == 'Y') dist[i][j] = pll(1, A[i] + A[j]);
  }
  REP(k, 0, N) REP(i, 0, N) REP(j, 0, N) {
    auto [hop1, souv1] = dist[i][k];
    auto [hop2, souv2] = dist[k][j];
    ll new_hop = hop1 + hop2;
    ll new_souv = souv1 + souv2 - A[k];
    auto [o_hop, o_souv] = dist[i][j];
    if (new_hop < o_hop or (new_hop == o_hop and new_souv > o_souv)) dist[i][j] = pll(new_hop, new_souv);
  }

  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll u, v; cin >> u >> v; u--; v--;
    auto [hop, souv] = dist[u][v];
    if (hop >= big) {
      cout << "Impossible\n";
    }else {
      cout << hop << " " << souv << "\n";
    }
  }

  return 0;
}

