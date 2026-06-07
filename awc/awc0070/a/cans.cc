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

  ll N, Y, M; cin >> N >> Y >> M;
  // @InpMVec(N, (A, B, P, Q, C)) [ty8o2Noy]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  auto P = vector(N, ll());
  auto Q = vector(N, ll());
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
    ll v3; cin >> v3; P[i] = v3;
    ll v4; cin >> v4; Q[i] = v4;
    ll v5; cin >> v5; C[i] = v5;
  }
  // @End [ty8o2Noy]

  ll ans1 = 0;
  ll ans2 = 0;

  ll Y2 = Y, M2 = M + 1;
  if (M == 12) {
    Y2 = Y + 1;
    M2 = 1;
  }
  

  REP(i, 0, N) {
    if (P[i] == Y and Q[i] == M) ans1 += C[i];
    else if (P[i] == Y2 and Q[i] == M2) ans2 += C[i];
  }
  cout << ans1 << " " << ans2 << endl;

  return 0;
}

