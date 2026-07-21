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

  ll N, M, Q; cin >> N >> M >> Q;
  // @InpVec(N, A) [wfOwYkGd]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [wfOwYkGd]
  // @InpVec(M, C) [K8cPG4CX]
  auto C = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; C[i] = v; }
  // @End [K8cPG4CX]
  vector<ll> cnt(M);
  REP(i, 0, Q) {
    ll p, d; cin >> p >> d; p--; d--;
    cnt[d]++;
  }
  REP(i, 0, M) {
    cout << min(cnt[i], C[i]) << "\n";
  }
  return 0;
}

