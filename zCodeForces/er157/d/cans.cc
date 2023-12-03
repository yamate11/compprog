#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using ull = unsigned long long;
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

  ll N; cin >> N;
  // @InpVec(N - 1, A) [DBd0MxBE]
  auto A = vector(N - 1, ll());
  for (int i = 0; i < N - 1; i++) { ll v; cin >> v; A[i] = v; }
  // @End [DBd0MxBE]

  vector B(N, 0LL);
  REP(i, 0, N - 1) B[i + 1] = B[i] ^ A[i];
  ull bc = bit_ceil((ull)N);
  ll k = countl_zero(bc);
  vector cnt0(k, 0LL);
  vector cnt1(k, 0LL);
  REP(i, 0, N) {
    ll x = B[i];
    REP(j, 0, k) {
      if (x % 2 == 0) cnt0[j]++;
      else cnt1[j]++;
      x /= 2;
    }
  }
  ll shift = 0;
  REP(i, 0, k) {
    if (cnt1[i] > cnt0[i]) shift |= (1LL << i);
  }
  REP(i, 0, N) B[i] ^= shift;
  REPOUT(i, 0, N, B[i], " ");

  return 0;
}

