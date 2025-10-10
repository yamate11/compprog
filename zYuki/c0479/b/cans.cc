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
  // @InpMVec(N, (A, B)) [iPjkpVmf]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
  }
  // @End [iPjkpVmf]

  ll c8 = 0, c4 = 0, c2 = 0;
  REP(i, 0, N) {
    ll a = A[i], b = B[i];
    if (a % 8 == 0) {
      c8 += b;
    }else if (a % 4 == 0) {
      c4 += b;
    }else if (a % 2 == 0) {
      c2 += b;
    }
  }
  ll ans = c8;
  if (c4 <= c2) {
    ans += c4 + (c2 - c4) / 3;
  }else {
    ans += c2 + (c4 - c2) / 2;
  }
  cout << ans << endl;

  return 0;
}

