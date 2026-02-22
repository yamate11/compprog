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
  // @InpVec(N, A, dec=1) [2cbjadki]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [2cbjadki]

  vector<ll> cnt1(N);
  vector<ll> cnt2(N);
  ll nk1 = 0;
  ll nk2 = 0;
  REP(i, 0, N) {
    if (cnt2[A[i]]++ == 0) nk2++;
  }
  ll ans = 0;
  REP(i, 0, N - 1) {
    if (cnt1[A[i]]++ == 0) nk1++;
    if (--cnt2[A[i]] == 0) nk2--;
    ans = max(ans, nk1 + nk2);
  }
  cout << ans << endl;
  return 0;
}

