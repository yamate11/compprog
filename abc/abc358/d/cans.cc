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

  ll N, M; cin >> N >> M;
  // @InpVec(N, A) [tLmx3M6M]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [tLmx3M6M]
  // @InpVec(M, B) [k7L6JM2B]
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
  // @End [k7L6JM2B]

  multiset<ll> AA;
  REP(i, 0, N) AA.insert(A[i]);
  sort(ALL(B));
  
  ll ans = 0;
  for (ll b : B) {
    auto it = AA.lower_bound(b);
    if (it == AA.end()) {
      cout << -1 << endl;
      return 0;
    }
    ans += *it;
    AA.erase(it);
  }
  cout << ans << endl;

  return 0;
}

