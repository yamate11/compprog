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

  ll N, D; cin >> N >> D;
  // @InpMVec(N, (X, S)) [HKGNkbCZ]
  auto X = vector(N, ll());
  auto S = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; X[i] = v1;
    ll v2; cin >> v2; S[i] = v2;
  }
  // @End [HKGNkbCZ]

  vector<pll> XS(N);
  REP(i, 0, N) XS[i] = pll(X[i], S[i]);
  ranges::sort(XS);

  vector<ll> B(N + 1);
  REP(i, 0, N) B[i + 1] = B[i] + XS[i].second;
  ll ans = 0;
  REP(i, 0, N) {
    ll j = ranges::lower_bound(XS, pll(XS[i].first + D + 1, 0LL)) - XS.begin();
    ans += XS[i].second * (B[j] - B[i + 1]);
  }
  cout << ans << endl;
  return 0;
}

