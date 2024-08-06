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
  // @InpVec(N, A) [pd86icyc]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [pd86icyc]

  using s_t = tuple<ll, ll, ll>;
  priority_queue<s_t, vector<s_t>, greater<s_t>> pque;
  REP(i, 0, N) {
    pque.emplace(3 * A[i], A[i], 1);
  }
  REP(i, 0, N - 2) {
    auto [v, a, d] = pque.top(); pque.pop();
    ll new_d = d + 1;
    ll new_v = ((new_d + 1) * (new_d + 1) - new_d * new_d) * a;
    pque.emplace(new_v, a, new_d);
  }
  ll ans = 0;
  while (not pque.empty()) {
    auto [v, a, d] = pque.top(); pque.pop();
    ans += d * d * a;
  }
  cout << ans << endl;

  return 0;
}

