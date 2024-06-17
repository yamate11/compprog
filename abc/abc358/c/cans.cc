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
  // @InpVec(N, S, type=string) [AdJrjCYo]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [AdJrjCYo]

  vector<ll> T(N, 0LL);
  REP(i, 0, N) {
    REP(j, 0, M) {
      if (S[i][j] == 'o') T[i] |= (1LL << j);
    }
  }
  ll ans = 1e18;
  REP(x, 0, 1LL << N) {
    ll a = 0;
    REP(i, 0, N) {
      if (x >> i & 1) a |= T[i];
    }
    if (a == ((1LL << M) - 1)) {
      ans = min(ans, (ll)popcount((u64)x));
    }
  }
  cout << ans << endl;

  return 0;
}

