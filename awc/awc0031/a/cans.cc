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

  ll N, M, K; cin >> N >> M >> K;
  vector<ll> V(N);
  vector T(N, vector<ll>());
  REP(j, 0, N) {
    cin >> V[j];
    ll C; cin >> C;
    REP(i, 0, C) {
      ll t; cin >> t;
      T[j].push_back(t);
    }
  }
  vector<pll> VI(N);
  REP(i, 0, N) VI[i] = pll(-V[i], i);
  ranges::sort(VI);
  vector<ll> A(M + 1);
  REP(ii, 0, K) {
    auto [tmp, j] = VI[ii];
    for (ll t : T[j]) A[t]++;
  }
  ll ans = 0;
  REP(t, 1, M + 1) if (A[t] == K) ans++;
  cout << ans << endl;

  return 0;
}

