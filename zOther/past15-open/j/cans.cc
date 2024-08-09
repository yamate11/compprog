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
  // @InpMVec(N, (A, B, X)) [a90Sd259]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  auto X = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
    ll v3; cin >> v3; X[i] = v3;
  }
  // @End [a90Sd259]

  vector<pll> vec;
  vector<ll> alloc(N, 0LL);
  REP(i, 0, N) vec.emplace_back(A[i], i);
  sort(ALL(vec), greater<pll>());
  ll p, q;
  REP(ii, 0, N) {
    auto [a, i] = vec[ii];
    if (X[i] == 0 and B[i] == 1) {
      alloc[i] = 0;
    }else {
      ll y = min(M, B[i] - 1);
      alloc[i] = y;
      M -= y;
    }
    if (M == 0) {
      p = ii + 1;
      q = ii;
    }
  }
  ll dmg = 0;
  REP(i, 0, N) {
    if (X[i] == 0) dmg += (B[i] - alloc[i] - 1) * A[i];
    else if (alloc[i] == 0) dmg += A[i] * B[i];
    else if (B[i] == 1) dmg += 0;
    else dmg += (B[i] - alloc[i] - 1) * A[i];
  }
  while (true) {
    while (p < N) {
      auto [a, i] = vec[p];
      if (X[i] == 1 and B[i] > 1) break;
      p++;
    }
    if (p == N) break;
    while (q >= 0) {
      auto [a, i] = vec[q];
      if (alloc[i] > 0 and (X[i] == 0 or (X[i] == 1 and (alloc[i] > 1 or B[i] == 1)))) {
        break;
      }
      q--;
    }
    if (q < 0) break;
    auto [a0, i0] = vec[p];
    auto [a1, i1] = vec[q];
    if (a0 >= 2 * a1) break;
    dmg += 2 * a1 - a0;
    alloc[i0]++;
    alloc[i1]--;
    p++;
  }
  cout << dmg << endl;

  return 0;
}

