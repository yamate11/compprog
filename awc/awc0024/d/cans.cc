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

  ll N, W, K; cin >> N >> W >> K;
  // @InpVec(K, L, dec=1) [VVonTmfA]
  auto L = vector(K, ll());
  for (int i = 0; i < K; i++) { ll v; cin >> v; v -= 1; L[i] = v; }
  // @End [VVonTmfA]

  vector<ll> vec(N + 1, 0LL);
  REP(i, 0, K) {
    vec[L[i]]++;
    vec[L[i] + W]--;
  }
  vector<ll> ans(N);
  ans[0] = vec[0];
  REP(i, 1, N) {
    ans[i] = ans[i - 1] + vec[i];
  }
  REPOUT(i, 0, N, ans[i], " ");
  return 0;
}

