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

// @@ !! LIM(binsearch)

// ---- inserted library file binsearch.cc

template <typename T>
requires integral<T>
T binsearch(auto check, T yes, T no) {
  while (abs(no - yes) > 1) {
    T mid = yes + (no - yes) / 2;  // avoiding unnecessary overflow
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

template <typename T>
requires floating_point<T>
T binsearch(auto check, T yes, T no, T err) {
  int rep = llround(ceil(log(abs(yes - no) / err) / log(2.0))) + 1;
  for (int r = 0; r < rep; r++) {
    T mid = (yes + no) / 2.0;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

// ---- end binsearch.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W, N; cin >> H >> W >> N;
  // @InpMVec(N, ((A, dec=1), (B, dec=1))) [Nu6BM0Fj]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; v1 -= 1; A[i] = v1;
    ll v2; cin >> v2; v2 -= 1; B[i] = v2;
  }
  // @End [Nu6BM0Fj]

  vector P(H + 1, vector(W + 1, 0));
  REP(i, 0, N) P[A[i] + 1][B[i] + 1] = 1;
  REP(i, 1, H + 1) REP(j, 1, W + 1) P[i][j] += P[i][j - 1];
  REP(i, 1, H + 1) REP(j, 1, W + 1) P[i][j] += P[i - 1][j];
  ll ans = 0;
  REP(i, 0, H) REP(j, 0, W) {
    auto check = [&](ll k) -> bool {
      return i + k <= H and j + k <= W and P[i + k][j + k] + P[i][j] - P[i + k][j] - P[i][j + k] == 0;
    };
    ll k = binsearch<ll>(check, 0, min(H, W) + 1);
    ans += k;
  }
  cout << ans << endl;
  return 0;
}

