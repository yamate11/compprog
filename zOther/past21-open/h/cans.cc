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

  ll N, K, L, M; cin >> N >> K >> L >> M;
  // @InpVec(K, D) [YVZ8yvDf]
  auto D = vector(K, ll());
  for (int i = 0; i < K; i++) { ll v; cin >> v; D[i] = v; }
  // @End [YVZ8yvDf]

  ll ans = 0;
  queue<ll> que;
  REP(i, 0, K) {
    while (not que.empty() and D[i] - que.front() >= L) que.pop();
    if (ssize(que) < M) {
      que.push(D[i]);
    }else {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

