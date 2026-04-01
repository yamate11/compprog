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
  // @InpVec(N, P) [O3Tlyul4]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; P[i] = v; }
  // @End [O3Tlyul4]
  REP(i, 0, M) {
    ll u, v, w; cin >> u >> v >> w; u--; v--;
    P[u] -= w;
    P[v] += w;
  }
  auto it = ranges::max_element(P);
  cout << it - P.begin() + 1 << endl;

  return 0;
}

