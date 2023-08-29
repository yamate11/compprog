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

using ull = unsigned long long;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(1LL << N, A, type=ull) [8oONYgVX]
  auto A = vector(1LL << N, ull());
  for (int i = 0; i < 1LL << N; i++) { ull v; cin >> v; A[i] = v; }
  // @End [8oONYgVX]
  REP(i, 0, 1LL << N) {
    ull t = 0;
    REP(k, 0, N) {
      if (i >> k & 1) t ^= A[1LL << k];
    }
    if (t != A[i]) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";

  return 0;
}

