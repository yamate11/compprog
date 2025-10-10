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
  // @InpVec(N, X) [X8q5RK7S]
  auto X = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; X[i] = v; }
  // @End [X8q5RK7S]
  sort(ALL(X));
  X.erase(unique(X.begin(), X.end()), X.end());
  N = ssize(X);
  vector D(N - 1, 0LL);
  REP(i, 0, N - 1) D[i] = X[i + 1] - X[i];
  sort(ALL(D));
  ll ans = 0;
  if (M - 1 >= N - 1) {
    ans = 0;
  }else {
    REP(i, 0, N - M) ans += D[i];
  }
  cout << ans << endl;

  return 0;
}

