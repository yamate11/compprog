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
  // @InpVec(N, A, dec=1) [19YkPoxm]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [19YkPoxm]

  vector vec(N, vector<ll>());
  REP(i, 0, N) vec[A[i]].push_back(i);
  ll ans = 0;
  REP(i, 0, N) {
    const auto& V = vec[i];
    ll m = ssize(V);
    vector<ll> S(m + 1, 0LL); REP(j, 0, m) S[j + 1] = S[j] + V[j];
    REP(j, 0, m) {
      ll t = (S[m] - S[j + 1]) - (m - j - 1) * V[j] - (m - j - 1) * (m - j) / 2;
      ans += t;
    }
  }
  cout << ans << endl;
  return 0;
}

