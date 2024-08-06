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
    // @InpVec(N, A) [rAIeXwGY]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [rAIeXwGY]
    vector<ll> even, odd;
    REP(i, 0, N) {
      if (A[i] % 2 == 0) even.push_back(A[i]);
      else odd.push_back(A[i]);
    }
    if (even.empty() or odd.empty()) return 0;
    ll x = *max_element(ALL(odd));
    sort(ALL(even));
    ll k = ssize(even);
    REP(i, 0, k) {
      if (x < even[i]) return k + 1;
      x += even[i];
    }
    return k;
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) cout << solve() << "\n";

  return 0;
}

