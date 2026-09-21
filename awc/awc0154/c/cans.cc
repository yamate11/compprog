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

  ll N, K, Q; cin >> N >> K >> Q;
  // @InpVec(N, C) [8BSQvhk8]
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
  // @End [8BSQvhk8]
  vector<ll> diff(N + 1);
  REP(q, 0, Q) {
    ll l, r; cin >> l >> r; l--;
    diff[l] += K;
    diff[r] -= K;
  }
  vector<ll> ans(N);
  ll cur = 0;
  REP(i, 0, N) {
    cur += diff[i];
    ans[i] = C[i] + cur;
  }
  REPOUT(i, 0, N, ans[i], " ");

  return 0;
}

