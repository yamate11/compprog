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
  // @InpVec(N, H) [4OUut46g]
  auto H = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; H[i] = v; }
  // @End [4OUut46g]

  ll big = 1e18;
  using tpA = tuple<ll, ll, ll>;  // height, volume, idx
  vector<tpA> stack;
  stack.emplace_back(big, 0, 0);
  ll cvol = 0;
  vector<ll> ans;
  REP(i, 0, N) {
    while (true) {
      auto [h, v, idx] = stack.back();
      if (h > H[i]) {
        cvol = v + H[i] * (i + 1 - idx);
        ans.push_back(cvol);
        stack.emplace_back(H[i], cvol, i + 1);
        break;
      }else {
        stack.pop_back();
      }
    }
  }
  REPOUT(i, 0, N, ans[i] + 1, " ");

  return 0;
}

