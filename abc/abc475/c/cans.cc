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

  ll N, S, L; cin >> N >> S >> L; S--;
  // @InpVec(N - 1, A) [W1HWflwe]
  auto A = vector(N - 1, ll());
  for (int i = 0; i < N - 1; i++) { ll v; cin >> v; A[i] = v; }
  // @End [W1HWflwe]
  vector<ll> B(N);
  REP(i, 0, N - 1) B[i + 1] = B[i] + A[i];
  ll ans = 1;
  REP(i, 0, N) {
    if (i == S) continue;
    else if (i < S) {
      ll a = B[S] - B[i];
      if (a > L) continue;
      ll j = ranges::lower_bound(B, B[i] + (L - a) + 1) - B.begin();
      ll cur = max(S, j) - i;
      ans = max(ans, cur);
      ans = max(ans, S - i + 1);
    }else if (i > S) {
      ll a = B[i] - B[S];
      if (a > L) continue;
      ll j = ranges::lower_bound(B, B[i] - (L - a)) - B.begin();
      ll cur = i - min(S, j) + 1;
      ans = max(ans, cur);
      ans = max(ans, i - S + 1);
    }
  }
  cout << ans << "\n";
  

  return 0;
}

