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

  ll N, K; cin >> N >> K;
  // @InpVec(N, p) [4PUljwSo]
  auto p = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; p[i] = v; }
  // @End [4PUljwSo]

  ll cur = 0;
  REP(i, 0, K) cur += p[i];
  ll vmax = cur;
  REP(i, K, N) {
    cur = cur + p[i] - p[i - K];
    vmax = max(vmax, cur);
  }
  cout << (vmax + K) / 2.0 << endl;

  return 0;
}

