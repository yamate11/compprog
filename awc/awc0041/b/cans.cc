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
  // @InpVec(M - 1, W) [0P5NeFLw]
  auto W = vector(M - 1, ll());
  for (int i = 0; i < M - 1; i++) { ll v; cin >> v; W[i] = v; }
  // @End [0P5NeFLw]
  // @InpVec(N, B) [7YnuQcyO]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [7YnuQcyO]

  REP(i, 1, M - 1) W[i] = max(W[i - 1], W[i]);

  REP(i, 0, N) {
    auto f = [&]() -> ll {
      ll j = ranges::lower_bound(W, B[i] + 1, less<ll>()) - W.begin();
      return j;
    };
    cout << f() + 1 << "\n";
  }

  return 0;
}

