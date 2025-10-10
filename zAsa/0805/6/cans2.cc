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

struct myexc : exception {};

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, K; cin >> N >> M >> K;
  // @InpNbrList(N, M, nbr, dec=1) [TBiJCcvH]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [TBiJCcvH]
  // @InpVec(N, A) [eRS9s3k0]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [eRS9s3k0]
  // @InpVec(K, B) [mbvVeSa4]
  auto B = vector(K, ll());
  for (int i = 0; i < K; i++) { ll v; cin >> v; B[i] = v; }
  // @End [mbvVeSa4]

  vector<bool> visited(N);

  auto func = [&](auto& front, ll goal) -> vector<ll> {
    vector<ll> nxt_front;
    auto dfs = [&](auto rF, ll nd) -> void {
      if (visited[nd]) return;
      if (A[nd] == goal) {
        nxt_front.push_back(nd);
        return;
      }
      visited[nd] = true;
      if (nd == N - 1) throw myexc();
      for (ll peer : nbr[nd]) rF(rF, peer);
    };
    for (ll f : front) dfs(dfs, f);
    return nxt_front;
  };

  vector<ll> front{0};
  try {
    REP(i, 0, K) {
      front = func(front, B[i]);
    }
    cout << "Yes\n";
  }catch(myexc& e) {
    cout << "No\n";
  }

  return 0;
}

