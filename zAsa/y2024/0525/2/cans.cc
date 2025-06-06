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
  // @InpVec(N, S) [OMaV4z7c]
  auto S = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; S[i] = v; }
  // @End [OMaV4z7c]
  // @InpVec(N, T) [RnUlo3BI]
  auto T = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; T[i] = v; }
  // @End [RnUlo3BI]

  priority_queue<pll, vector<pll>, greater<pll>> pque;
  REP(i, 0, N) pque.emplace(T[i], i);
  vector<ll> ans(N, -1LL);
  while (not pque.empty()) {
    auto [t, i] = pque.top(); pque.pop();
    if (ans[i] < 0) {
      ans[i] = t;
      pque.emplace(t + S[i], (i + 1) % N);
    }
  }
  REPOUT(i, 0, N, ans[i], "\n");

  return 0;
}

