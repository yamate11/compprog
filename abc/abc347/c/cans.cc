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

  ll N, A, B; cin >> N >> A >> B;
  // @InpVec(N, D) [0Wfdn7HX]
  auto D = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; D[i] = v; }
  // @End [0Wfdn7HX]

  ll P = A + B;
  set<ll> ss;
  REP(i, 0, N) {
    ll x = D[i] % P;
    ss.insert(x);
    ss.insert(x + P);
  }
  for (ll x : ss) {
    if (x >= P) break;
    auto it1 = ss.lower_bound(x + A);
    auto it2 = ss.lower_bound(x + P);
    if (it1 == it2) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
  return 0;
}
