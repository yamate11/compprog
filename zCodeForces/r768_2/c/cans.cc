#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

using pll = pair<ll, ll>;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll N, K; cin >> N >> K;
    vector<pll> ans;
    auto comp = [&](ll x) { return (~x) & (N - 1); };
    auto pout = [&](ll p, ll q) { ans.emplace_back(p, q); };

    if (N == 4 and K == 3) {
      cout << -1 << "\n";
      return; 
    }
    if (K == 0) {
      REP(x, N / 2) pout(x, comp(x));
    }else if (K == N - 1) {
      pout(comp(0), comp(1));
      pout(1, 3);
      pout(0, comp(3));
      pout(2, comp(2));
      REP2(x, 4, N / 2) pout(x, comp(x));
    }else {
      pout(N - 1, K);
      pout(0, comp(K));
      REP2(x, 1, N / 2) if (x != K and x != comp(K)) pout(x, comp(x));
    }
#if DEBUG
    ll v = 0;
    for (auto [p, q] : ans) v += p & q;
    assert(v == K && "wrong answer");
#endif    
    for (auto [p, q] : ans) cout << p << " " << q << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

