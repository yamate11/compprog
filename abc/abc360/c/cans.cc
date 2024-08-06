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

  ll N; cin >> N;
  // @InpVec(N, A, dec=1) [Qwt7qoRY]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [Qwt7qoRY]
  // @InpVec(N, W) [q6JodZ35]
  auto W = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; W[i] = v; }
  // @End [q6JodZ35]

  vector vec(N, vector<ll>());
  REP(i, 0, N) {
    vec[A[i]].push_back(W[i]);
  }
  ll ans = 0;
  REP(i, 0, N) {
    if (ssize(vec[i]) >= 2) {
      sort(ALL(vec[i]), greater<ll>());
      REP(j, 1, ssize(vec[i])) ans += vec[i][j];
    }
  }
  cout << ans << endl;
  return 0;
}

