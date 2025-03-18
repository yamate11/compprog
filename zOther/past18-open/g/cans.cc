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

  auto solve = [&]() -> bool {
    ll N; cin >> N;
    // @InpVec(N, A) [xBiGbEcE]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [xBiGbEcE]
    // @InpVec(N, B) [dg3wCB8h]
    auto B = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
    // @End [dg3wCB8h]

    vector v0(N + 1, false);
    vector v1(N + 1, false);
    vector v2(N + 1, false);
    v0[0] = true;
    v1[0] = false;
    v2[0] = false;
    REP(i, 0, N) {
      if (v0[i] and A[i] == B[i]) v0[i + 1] = true;
      if (v1[i] and A[i] == B[i]) v1[i + 1] = true;
      if (v2[i] and A[i] == B[i]) v2[i + 1] = true;
      if (v0[i] and i + 1 < N and B[i] == A[i + 1] and B[i + 1] == A[i]) v1[i + 2] = true;
      if (v0[i] and i + 1 < N and A[i] == B[i] and A[i + 1] == B[i + 1]) v2[i + 2] = true;
      if (v1[i] and i + 1 < N and B[i] == A[i + 1] and B[i + 1] == A[i]) v2[i + 2] = true;
      if (v0[i] and i + 2 < N and B[i] == A[i + 1] and B[i + 1] == A[i + 2] and B[i + 2] == A[i]) v2[i + 3] = true;
      if (v0[i] and i + 2 < N and B[i] == A[i + 2] and B[i + 1] == A[i] and B[i + 2] == A[i + 1]) v2[i + 3] = true;
    }
    return v2[N];
  };
  cout << (solve() ? "Yes\n" : "No\n");

  return 0;
}

