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
  // @InpVec(N, A) [O25x2V7d]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [O25x2V7d]
  vector<ll> B;
  REP(i, 2, N) B.push_back(A[i]);
  sort(ALL(B));
  ll cost = 1e18;
  REP(i, 0, N - M - 1) {
    ll moveL = max(0LL, A[0] - B[i]);
    ll moveH = max(0LL, B[i + M - 1] - A[1]);
    cost = min(cost, moveL + moveH);
  }
  cout << cost << endl;

  return 0;
}

