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
  // @InpVec(M, A, dec=1) [lgsNFeLl]
  auto A = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [lgsNFeLl]

  vector<ll> vote(N);
  set<pll> ss;
  REP(i, 0, M) {
    ss.erase(pll(-vote[A[i]], A[i]));
    vote[A[i]]++;
    ss.insert(pll(-vote[A[i]], A[i]));
    auto [n, j] = *ss.begin();
    cout << j + 1 << "\n";
  }

  return 0;
}

