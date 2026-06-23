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

  ll N, S, K; cin >> N >> S >> K;
  // @InpVec(N - 1, E) [bsUgjMLi]
  auto E = vector(N - 1, ll());
  for (int i = 0; i < N - 1; i++) { ll v; cin >> v; E[i] = v; }
  // @End [bsUgjMLi]
  ll u = 0;
  ll p = S;
  REP(i, 0, N - 1) {
    if (p < E[i]) {
      ll d = E[i] - p;
      u += d;
      p += d;
    }
    p += E[i];
  }
  if (u > K) {
    cout << -1 << endl;
  }else {
    cout << u << endl;
  }

  return 0;
}

