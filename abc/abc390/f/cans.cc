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

  ll N; cin >> N;
  // @InpVec(N, A, dec=1) [54VCt7eQ]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [54VCt7eQ]

  ll ans = 0;
  ll cur = 0;
  vector lastPos(N, -1LL);
  REP(i, 0, N) {
    ll p = A[i];
    ll p_lo, p_hi, p_just;
    if (p > 0) {
      p_lo = lastPos[p - 1];
    }else {
      p_lo = -1;
    }
    if (p < N - 1) {
      p_hi = lastPos[p + 1];
    }else {
      p_hi = -1;
    }
    p_just = lastPos[p];
    ll p1 = max(p_lo, p_hi);
    ll p2 = min(p_lo, p_hi);
    if (p1 < 0) {
      cur += i - p_just;
    }else if (p_just > p1) {
      cur += i - p_just;
    }else if (p_just >= p2) {
      cur += i - p1;
    }else {
      cur += (i - p1) - (p2 - p_just);
    }
    ans += cur;
    lastPos[p] = i;
  }
  cout << ans << endl;
  return 0;
}

