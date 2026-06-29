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
  // @InpVec(N, A) [bW64Z7Cg]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [bW64Z7Cg]

  set<ll> ss;
  REP(i, 0, N) ss.insert(i);
  vector<ll> ans(N);
  
  while (not ss.empty()) {
    auto it = ss.begin();
    ll i0 = *it;
    ans[i0] = -1;
    it = ss.erase(it);
    while (it != ss.end()) {
      if (A[i0] <= A[*it]) break;
      ans[*it] = i0;
      i0 = *it;
      it = ss.erase(it);
    }
  }
  REPOUT(i, 0, N, ans[i] + 1, " ");

  return 0;
}

