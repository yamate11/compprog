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

  ll N, M, K; cin >> N >> M >> K;
  // @InpVec(M, C) [X6tuNfwb]
  auto C = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; C[i] = v; }
  // @End [X6tuNfwb]
  ll rem = 0;
  REP(i, 0, M) {
    if (C[i] >= N) K--;
    else rem += C[i];
  }
  bool b = rem >= K * N;
  cout << (b ? "Yes\n" : "No\n");

  return 0;
}

