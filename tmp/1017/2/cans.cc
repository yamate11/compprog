#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  // @InpVec(N, A) [1V31YcBg]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [1V31YcBg]
  map<ll, vector<ll>> mp;
  REP(i, 0, N) mp[A[i]].push_back(i);
  REP(_q, 0, Q) {
    ll x, k; cin >> x >> k;
    auto it = mp.find(x);
    ll ans = -1;
    if (it != mp.end()) {
      auto& vec = it->second;
      if (k - 1 < SIZE(vec)) ans = vec[k - 1] + 1;
    }
    cout << ans << "\n";
  }

  return 0;
}

