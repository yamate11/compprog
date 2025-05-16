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
  // @InpVec(N, P) [oTeC4jmz]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; P[i] = v; }
  // @End [oTeC4jmz]
  vector<pll> Q(N);
  REP(i, 0, N) Q[i] = pll(P[i], i);
  sort(ALL(Q), greater<pll>());
  vector<ll> ans(N);
  ll r = 0;
  REP(i, 0, N) {
    if (i == 0 or Q[i - 1].first != Q[i].first) {
      r = i;
    }
    ans[Q[i].second] = r;
  }
  REPOUT(i, 0, N, ans[i] + 1, "\n");

  return 0;
}

