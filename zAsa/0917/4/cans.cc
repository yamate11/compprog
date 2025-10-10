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

  ll N, C, K; cin >> N >> C >> K;
  // @InpVec(N, T) [LLkuCsb6]
  auto T = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; T[i] = v; }
  // @End [LLkuCsb6]
  sort(ALL(T));

  ll ans = 0;
  ll timeout = -1;
  ll onbus = 0;
  REP(i, 0, N) {
    ll t = T[i];
    if (timeout < 0 or timeout < t or onbus == C) {
      ans++;
      onbus = 1;
      timeout = t + K;
    }else {
      onbus++;
    }
  }
  cout << ans << endl;

  return 0;
}

