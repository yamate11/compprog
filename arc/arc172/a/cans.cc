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

  ll H, W, N; cin >> H >> W >> N;
  // @InpVec(N, A) [s7Ae134I]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [s7Ae134I]
  ll sb = 26;
  vector B(sb, 0LL);
  REP(i, 0, N) B[A[i]]++;

  ll sc = 32;
  vector C(sc, 0LL);
  REP(i, 0, sc) {
    if (H >> i & 1) {
      REP(j, 0, sc) {
        if (W >> j & 1) {
          ll a = min(i, j), b = max(i, j);
          C[a] += (1LL << (b - a));
        }
      }
    }
  }

  ll c = sc - 1;
  REPrev(b, sb - 1, 0) {
    if (B[b] == 0) continue;
    while (c > b) {
      if (C[c] > 0) {
        C[b] += C[c] * (1LL << (2 * (c - b)));
        C[c] = 0;
      }
      c--;
    }
    assert(b == c);
    if (B[b] > C[c]) {
      cout << "No\n";
      return 0;
    }
    C[c] -= B[b];
  }
  cout << "Yes\n";


  return 0;
}

