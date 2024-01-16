#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
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
  ll X, Y; cin >> X >> Y;
  // @InpVec(N, A) [vzs5MWg8]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [vzs5MWg8]
  // @InpVec(M, B) [w144xpkA]
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
  // @End [w144xpkA]

  auto proceed = [&](auto& vec, ll idx, ll limit, ll advance) -> void {
    for (; idx < limit and vec[idx] < time; idx++);
    time = idx == limit ? big : vec[idx] + advance;
  };

  ll i = 0;
  ll j = 0;
  ll ans = 0;
  ll time = 0;
  ll big = 1e18;
  while (time < big) {
    proceed(A, i, N, X);
    proceed(B, j, M, Y);
    ans++;
  }
  cout << ans << endl;
  return 0;
}

