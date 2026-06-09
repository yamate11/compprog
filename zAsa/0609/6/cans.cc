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
  // @InpGrid(N, M, A) [UgbzsRY0]
  auto A = vector(N, vector(M, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [UgbzsRY0]
  
  using mybs = bitset<2048>;
  vector<mybs> tbl(N);
  ll limval = 1000;
  REP(j, 0, M) {
    vector vec(limval, vector<ll>());
    REP(i, 0, N) vec[A[i][j]].push_back(i);
    REP(x, 1, limval) if (not vec[x].empty()) {
      mybs bs;
      for (ll i : vec[x]) bs[i] = true;
      for (ll i : vec[x]) tbl[i] ^= bs;
    }
  }
  ll ans = 0;
  REP(i, 0, N) ans += tbl[i].count();
  if (M % 2 != 0) ans -= N;
  ans /= 2;
  cout << ans << endl;

  return 0;
}

