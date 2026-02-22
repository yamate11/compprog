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
  // @InpGrid(N, 3, P) [nC3JVSsb]
  auto P = vector(N, vector(3, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < 3; j++) { ll v; cin >> v; P[i][j] = v; }
  // @End [nC3JVSsb]
  
  vector M(N, 0LL);
  REP(i, 0, N) REP(j, 0, 3) M[i] += P[i][j];
  auto A = M;
  ranges::sort(A);
  REP(i, 0, N) {
    ll x = A.end() - ranges::lower_bound(A, M[i] + 300 + 1);
    cout << (x + 1 <= K ? "Yes\n" : "No\n");
  }

  return 0;
}

