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

  auto solve = [&]() -> ll {
    ll N, M; cin >> N >> M;
    // @InpVec(N, A) [UXnF2m6c]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [UXnF2m6c]
    // @InpVec(N, B) [3pBTLRuv]
    auto B = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
    // @End [3pBTLRuv]
    ll tot = accumulate(ALL(A), 0LL);
    tot += accumulate(ALL(B), 0LL);
    multiset<ll> P;
    REP(i, 0, N) P.insert(A[i]);
    ll cnt = 0;
    for (ll x : B) {
      if (x == 0) continue;
      auto it = P.lower_bound(M - x);
      if (it == P.end()) continue;
      cnt++;
      P.erase(it);
    }
    tot -= cnt * M;
    return tot;
  };


  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

