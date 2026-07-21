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
  // @InpVec(N, T) [Mbnsrbyv]
  auto T = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; T[i] = v; }
  // @End [Mbnsrbyv]

  vector<ll> D(N + 1);
  ll cur = 0;
  REP(i, 0, N) {
    cur += D[i];
    if (cur > T[i]) {
      cout << "No\n";
      return 0;
    }
    if (i + K > N and cur != T[i]) {
      cout << "No\n";
      return 0;
    }
    ll e = T[i] - cur;
    if (e != 0) {
      D[i + K] -= e;
    }
    cur = T[i];
  }
  cout << "Yes\n";
  return 0;
}

