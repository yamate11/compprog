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

  ll N, K; cin >> N >> K;
  // @InpVec(N, A) [Aif8D1jj]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [Aif8D1jj]

  ll ans = 0;
  multiset<ll> ss;
  ll p = 0;
  REP(q, 0, N) {
    while (p < N) {
      if (ss.empty()) {
        ss.insert(A[p++]);
      }else {
        ll lo = *ss.begin();
        ll hi = *std::prev(ss.end());
        if (max(hi, A[p]) - min(lo, A[p]) > K) break;
        ss.insert(A[p++]);
      }
      ans = max(ans, p - q);
    }
    auto it = ss.find(A[q]);
    ss.erase(it);
  }
  cout << ans << endl;
  
  return 0;
}

