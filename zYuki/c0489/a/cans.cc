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
    ll N; cin >> N;
    // @InpVec(N, A) [jgFwHzDS]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [jgFwHzDS]
    vector<ll> pos, neg;
    REP(i, 0, N) {
      if (A[i] >= 0) pos.push_back(A[i]);
      else neg.push_back(A[i]);
    }
    ranges::sort(pos);
    ranges::sort(neg, greater<ll>());
    if (neg.empty()) return pos[0] * pos[1];
    if (pos.empty()) return neg[0] * neg[1];
    return pos[0] * neg[0];
  };


  ll T; cin >> T;
  REP(i, 0, T) cout << solve() << endl;

  return 0;
}

