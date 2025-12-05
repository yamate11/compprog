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
  // @InpVec(N, A) [aogpBavx]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [aogpBavx]

  vector<ll> cnt(30);
  REP(i, 0, N) {
    REP(k, 0, 30) {
      cnt[k] += (A[i] >> k & 1);
    }
  }
  ll ans = accumulate(ALL(A), 0LL);
  REP(i, 0, N) {
    ll s = 0;
    REP(k, 0, 30) {
      ll n = (A[i] >> k & 1) ? N - cnt[k] : cnt[k];
      s += (n << k);
    }
    ans = max(ans, s);
  }
  cout << ans << endl;
  return 0;
}

