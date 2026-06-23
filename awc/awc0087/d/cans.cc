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
  // @InpVec(N, X) [lB0SCs4i]
  auto X = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; X[i] = v; }
  // @End [lB0SCs4i]
  vector<ll> pos;
  vector<ll> neg;
  REP(i, 0, N) {
    if (X[i] > 0) pos.push_back(X[i]);
    else if (X[i] < 0) neg.push_back(-X[i]);
    else assert(0);
  }
  
  auto f = [&](auto& vec) -> ll {
    ll sz = ssize(vec);
    ranges::sort(vec, greater<ll>());
    ll ret = 0;
    for (ll i = 0; i < sz; i += K) ret += vec[i];
    return 2 * ret;
  };

  ll ans1 = f(pos);
  ll ans2 = f(neg);
  ll ans = ans1 + ans2;
  cout << ans << endl;

  return 0;
}

