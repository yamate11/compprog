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
  // @InpVec(N, A) [zzGzEg5S]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [zzGzEg5S]

  ll K = 30;
  vector<ll> cnt1(K);
  REP(k, 0, K) REP(i, 0, N) if (A[i] >> k & 1) cnt1[k]++;
  ll ans = accumulate(ALL(A), 0LL);
  REP(i, 0, N) {
    ll cur = 0;
    REP(k, 0, K) {
      if (A[i] >> k & 1) cur += (N - cnt1[k]) << k;
      else cur += cnt1[k] << k;
    }
    ans = max(ans, cur);
  }
  cout << ans << endl;

  return 0;
}

