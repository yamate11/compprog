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
  // @InpMVec(N, (A, B)) [Z4RtBqyH]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
  }
  // @End [Z4RtBqyH]
  // @InpMVec(M, (C, D)) [Odb0RIe0]
  auto C = vector(M, ll());
  auto D = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; C[i] = v1;
    ll v2; cin >> v2; D[i] = v2;
  }
  // @End [Odb0RIe0]

  REP(i, 0, N) {
    vector<ll> ord(M);
    REP(j, 0, M) ord[j] = j;
    sort(ALL(ord), [&](ll p, ll q) -> bool {
      ll dp = abs(C[p] - A[i]) + abs(D[p] - B[i]);
      ll dq = abs(C[q] - A[i]) + abs(D[q] - B[i]);
      if (dp != dq) return dp < dq;
      return p < q;
    });
    cout << ord[0] + 1 << "\n";
  
  }

  return 0;
}

