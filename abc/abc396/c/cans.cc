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
  // @InpVec(N, B) [F3K4zmRk]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [F3K4zmRk]
  // @InpVec(M, W) [nwAMja44]
  auto W = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; W[i] = v; }
  // @End [nwAMja44]

  sort(ALL(B), greater<ll>());
  sort(ALL(W), greater<ll>());

  vector<ll> SB(N + 1);
  vector<ll> SW(M + 1);
  REP(i, 0, N) SB[i + 1] = SB[i] + B[i];
  REP(i, 0, M) SW[i + 1] = SW[i] + W[i];
  auto MB = SB;
  REPrev(i, N - 1, 0) {
    MB[i] = max(MB[i], MB[i + 1]);
  }
  ll ans = 0;
  REP(i, 0, min(N, M) + 1) ans = max(ans, MB[i] + SW[i]);
  cout << ans << endl;

  return 0;
}

