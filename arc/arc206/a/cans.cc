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
  // @InpVec(N, A, dec=1) [1j4FXhgY]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [1j4FXhgY]

  vector<vector<ll>> vec(N);
  REP(i, 0, N) vec[A[i]].push_back(i);
  ll ans = 1;
  REP(i, 0, N) {
    if (i < N - 1 and A[i] == A[i + 1]) continue;
    ll x = vec[A[i]].end() - lower_bound(ALL(vec[A[i]]), i + 1);
    ans += N - (i + 1) - x;
  }
  cout << ans << endl;
  return 0;
}

