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

  ll N, M, S; cin >> N >> M >> S;
  // @InpVec(N, D) [RG2ur5Va]
  auto D = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; D[i] = v; }
  // @End [RG2ur5Va]
  // @InpMVec(M, ((P, dec=1), R)) [I3YrfMBe]
  auto P = vector(M, ll());
  auto R = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; P[i] = v1;
    ll v2; cin >> v2; R[i] = v2;
  }
  // @End [I3YrfMBe]

  vector<ll> PP(N, 0LL);
  REP(i, 0, M) PP[P[i]] = R[i];

  bool dgd = false;
  REP(i, 0, N) {
    S -= (dgd ? 2 : 1) * D[i];
    if (S <= 0) dgd = true;
    S += PP[i];
  }
  cout << S << endl;
  return 0;
}

