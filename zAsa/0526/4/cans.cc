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
  // @InpVec(N, H) [csrY9FpX]
  auto H = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; H[i] = v; }
  // @End [csrY9FpX]
  ll big = 1LL << 60;
  vector<pll> stack{{big, N}};
  vector<ll> ans(N);
  REPrev(i, N - 1, 0) {
    ans[i] = ssize(stack) - 1;
    while (H[i] > stack.back().first) stack.pop_back();
    stack.emplace_back(H[i], i);
  }
  REPOUT(i, 0, N, ans[i], " ");
  return 0;
}

